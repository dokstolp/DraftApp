from flask import Flask, render_template, request, url_for, redirect, session, jsonify
from app import app
import sys
import playerdefs
import fundefs


@app.route('/')
@app.route('/get_username_index',methods=['GET','POST'])
def get_username_index():
	return render_template('login.html')

@app.route('/get_username',methods=['GET','POST'])
def get_username():
	user = 'Stolp'
	isMock = False
	pock = 11
	name = request.form['user']
	password = request.form['password']
	toRun = request.form['type']
	passp = 'myPassword'
	isSet = False
#	passp = 'GoFuckYourself'
#	print name
#	print toRun
	if(toRun == "Guest Mock"):
		user = "Guest"
		isMock = True
	if(toRun == "Guest Real"):
		user = "Guest"
		isMock = False
	if(password == passp):
		user = name
		if(toRun == "Mock Draft"):
			isMock = True
		if(toRun == "Real Draft"):
			isMock = False
		if(toRun == "myVal"):
			isSet = True
	else:
		return redirect(url_for('get_username_index'))
	session['isMock'] = isMock
	session['user'] = user
	if(isSet is True):
		return redirect(url_for('set_myVal'))
	return redirect(url_for('get_pick_index'))

@app.route('/set_myVal',methods=['GET','POST'])
def set_myVal():
	return render_template('myVal.html')

@app.route('/load_vals',methods=['GET','POST'])
def load_vals():
	outAr = playerdefs.getPosVals()
	outPlayers = playerdefs.getOutPlayers()
	qb = outAr['QB']
	rb = outAr['RB']
	wr = outAr['WR']
	te = outAr['TE']
	k = outAr['K']
	de = outAr['DE']
	return jsonify(players=outPlayers,qb=qb,rb=rb,wr=wr,te=te,k=k,de=de)

@app.route('/save_myAdj',methods=['GET','POST'])
def save_myAdj():
	playerdefs.saveAdj(request.form['player'],float(request.form['myadjust']),float(request.form['dpoints']))
	outPlayers = playerdefs.getOutPlayers()
	return jsonify(players=outPlayers)

@app.route('/save_posVals',methods=['GET','POST'])
def save_posVals():
	playerdefs.savePosVals(request.form['values'])
	outPlayers = playerdefs.getOutPlayers()
	return jsonify(players=outPlayers,qb=qb,rb=rb,wr=wr,te=te,k=k,de=de)


@app.route('/get_pick_index',methods=['GET','POST'])
def get_pick_index():
	#isMock = request.args.get('isMock')
	isMock = session['isMock']
	user = session['user']
	#isDusty = (user == "Dusty")
	print "In get pick is Dusty "+str(isMock)

	if(isMock):
		return render_template('start.html',user=user)
	else:
		return render_template('rstart.html',user=user)

@app.route('/get_pick',methods=['GET','POST'])
def get_pick():
	isMock = session['isMock']
	pock=request.form['picking']
	session['pock'] = pock
	if (isMock):
		lamb=request.form['diff']
		session['lamb'] = lamb
	else:
		lamb = 0
	if (pock is None or int(pock) < 1 or int(pock) > 10) or (lamb is None or int(lamb) < 0 or int(lamb) > 10):
		return redirect(url_for('get_pick_index'))
	else:
		print "in get_pick"
		return redirect(url_for('draft_index', pock=pock, lamb=lamb))

@app.route('/draft_index',methods=['GET','POST'])
def draft_index():
	pock = session['pock']
	lamb = session['lamb']
	user=session['user']
	isMock = session['isMock']
	#pock = request.args.get('pock')
	#lamb = request.args.get('lamb')
	return render_template("draft.html",user=user,lamb=lamb,pock=pock,isMock=isMock)

@app.route('/draft_temp',methods=['GET','POST'])
def draft_temp():
	pock = int(session['pock'])
	lamb = int(session['lamb'])
	isMock = session['isMock']
	print "in draft_temp "+str(pock)+"   "+str(lamb)+"   "+str(isMock)
	iter = 1
	teamList = []
	for t in range(10):
		teamList.append([])
	tplayers = playerdefs.setDustyValues(pock,playerdefs.setValues(pock,playerdefs.getList()),teamList[pock-1])
	players = playerdefs.setSelfie(tplayers)
	if isMock:
		print "players length in temp "+str(len(players))
		pRem = mockery(iter,pock,lamb,teamList,players)
		players = pRem['players']
		tteam = pRem['team']
		iter = pRem['iter']
		tplayers = sorted(players,key=playerdefs.getKeyD)
	elif int(pock) == int(iter):
		tteam = teamList
		tplayers = sorted(players,key=playerdefs.getKeyD)
	else:
		tteam = teamList
		tplayers = sorted(players,key=playerdefs.getKeyMC)
	round = int(iter-1)/10 + 1
	players=[e.serialize() for e in tplayers]
	team = []
	for lop in tteam:
		team.append([e.serialize() for e in lop])
	return jsonify(iter=iter,round=round,team=team,players=players)

@app.route('/draft',methods=['GET','POST'])
def draft():
	pock = int(session['pock'])
	lamb = int(session['lamb'])
	isMock = session['isMock']
	#iter = request.args.get('iter',0,type=int)
	#chosen = request.args.get('chosen',0,type=str)
	iter = int(request.form["iter"])
	chosen = int(request.form["chosen"])
	tList = request.form["teams"]
	pList = request.form["players"]
	#tList = request.args.get('teams',0,type=str)
	#pList = request.args.get('players',0,type=str)
	print "iter: "+str(iter)+"\tchosen: "+str(chosen)+"\ttList: "+tList+"\tpList: "+pList
	teamList = playerdefs.tLister(tList)
	players = playerdefs.pLister(pList)
	mypick = fundefs.returnPlayer(chosen,players)
	players.remove(mypick)
	mypick.setPicked(iter)
	teamList[fundefs.getTeam(iter)-1].append(mypick)
	iter+=1
	if (isMock):
		pRem = mockery(iter,pock,lamb,teamList,players)
		tteam = pRem['team']
		tplayers = pRem['players']
		iter = pRem['iter']
		players = playerdefs.setDustyValues(pock,tplayers,tteam[pock-1])
		tplayers = sorted(players,key=playerdefs.getKeyD)
	elif int(pock) == int(iter):
		tteam = teamList
		players = playerdefs.setDustyValues(pock,players,tteam[pock-1])
		tplayers = sorted(players,key=playerdefs.getKeyD)
	else:
		tteam = teamList
		players = playerdefs.setDustyValues(pock,players,tteam[pock-1])
		tplayers = sorted(players,key=playerdefs.getKeyMC)
	
	round = int(iter-1)/10 + 1
	players=[e.serialize() for e in tplayers]
	team = []
	for lop in tteam:
		team.append([e.serialize() for e in lop])
	return jsonify(iter=iter,round=round,team=team,players=players)

def mockery(iter,pock,lamb,teams,players):
	while(int(fundefs.getTeam(iter)) is not int(pock)):
		team = int(fundefs.getTeam(iter))
		autoplayer = playerdefs.autoPick(0,lamb,players,teams[team-1])
		teams[team-1].append(autoplayer)
		autoplayer.setPicked(iter)
		players.remove(autoplayer)
		iter+=1
	rets = {'players':players,'team':teams,'iter':iter}
	return rets
