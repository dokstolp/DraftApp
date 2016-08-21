from flask import Flask, render_template, request, url_for, redirect, session, jsonify, g
from app import app
import pymysql.cursors
import sys
import playerdefs
import fundefs

@app.before_request
def db_connect():
        g.db_conn = pymysql.connect(host='localhost',
                             user='',
                             password='',
                             db='NFL_Draft',
                             charset='utf8mb4',
                             local_infile=True,
                             cursorclass=pymysql.cursors.DictCursor)

@app.teardown_request
def db_disconnect(exception=None):
        g.db_conn.close()

#***************************************HomePage************************
@app.route('/')
@app.route('/get_username_index',methods=['GET','POST'])
def get_username_index():
	return render_template('login.html')


@app.route('/homepage',methods=['GET','POST'])
def homepage():
	toRun = request.form['type']
	if toRun == "login":
		checksOut = False
		username = request.form['username']
		password = request.form['password']
		checksOut = fundefs.checkUser(username,password)
		user = username
		if checksOut is True:
			session['user'] = username
			return redirect(url_for('userHomePage'))
		else:
			return redirect(url_for('get_username_index'))
	if toRun == "createUser":
		return render_template('newAccount.html')
	return redirect(url_for('get_username_index'))

#****************************************New User*******************************
@app.route('/newUserName',methods=['GET','POST'])
def newUserName():
	username = request.form['username']
	password = request.form['password']
	retype = request.form['retype']
	email = request.form['email']
	secret = request.form['secret']
	isUnused = fundefs.unusedUser(username,email)
	if isUnused and (password == retype) and (secret == 'GoPackGo'):
		user = username
		fundefs.addUser(username,password,email)
		session['user'] = username
		return render_template('homepage.html',user=user)
	else:
		return render_template('newAccount.html')

#****************************************Returning User*******************************
@app.route('/userHomePage',methods=['GET','POST'])
def userHomePage():
	username = session['user']
	if username is None:
		return redirect(url_for('get_username_index'))
	return render_template('homepage.html',user=username)
	


@app.route('/userPage',methods=['GET','POST'])
def userPage():
	user = session['user']
	if user is None:
		return redirect(url_for('get_username_index'))
	toRun = request.form['type']
	session['user'] = user
	if toRun == "Mock":
		return redirect(url_for('pick_mock_temp'))
	if toRun == "Real":
		return redirect(url_for('pick_real_temp'))
	if toRun == "SetValues":
		return redirect(url_for('set_values'))

#****************************************Mock*********************************
@app.route('/pick_mock_temp',methods=['GET','POST'])
def pick_mock_temp():
	user = session['user']
	if user is None:
		return redirect(url_for('get_username_index'))
	session['user'] = user
	return render_template('pick_mock.html',user=user)

@app.route('/get_pick_mock',methods=['GET','POST'])
def get_pick_mock():
	user = session['user'] 
	pock=request.form['picking']
	lamb=request.form['diff']
	session['user'] = user
	if (pock is None or int(pock) < 1 or int(pock) > 10) or (lamb is None or int(lamb) < 0 or int(lamb) > 10):
		return render_template("pick_mock.html",user=user)
	else:
		session['pock'] = pock
		session['lamb'] = lamb
		return render_template("start_mock.html",pock=pock,lamb=lamb)

@app.route('/mock_temp',methods=['GET','POST'])
def mock_temp():
	pock = int(session['pock'])
	lamb = int(session['lamb'])
	username = session['user']
	iter = 1
	teamList = []
	for t in range(10):
		teamList.append([])
	tplayers = playerdefs.setDustyValues(username,pock,playerdefs.setValues(pock,playerdefs.getList(username)),teamList[pock-1])
	players = playerdefs.setSelfie(tplayers)
	pRem = mockery(iter,pock,lamb,teamList,players)
	players = pRem['players']
	tteam = pRem['team']
	iter = pRem['iter']
	tplayers = sorted(players,key=playerdefs.getKeyD)
	round = int(iter-1)/10 + 1
	players=[e.serialize() for e in tplayers]
	team = []
	for lop in tteam:
		team.append([e.serialize() for e in lop])
	return jsonify(iter=iter,round=round,team=team,players=players)


@app.route('/mock',methods=['GET','POST'])
def mock():
	pock = int(session['pock'])
	lamb = int(session['lamb'])
	username = session['user']
	iter = int(request.form["iter"])
	chosen = int(request.form["chosen"])
	tList = request.form["teams"]
	pList = request.form["players"]
	teamList = playerdefs.tLister(tList)
	players = playerdefs.pLister(pList)
	mypick = fundefs.returnPlayer(chosen,players)
	players.remove(mypick)
	mypick.setPicked(iter)
	teamList[fundefs.getTeam(iter)-1].append(mypick)
	iter+=1
	pRem = mockery(iter,pock,lamb,teamList,players)
	tteam = pRem['team']
	tplayers = pRem['players']
	iter = pRem['iter']
	players = playerdefs.setDustyValues(username,pock,tplayers,tteam[pock-1])
	tplayers = sorted(players,key=playerdefs.getKeyD)
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


#*****************************************Draft********************************
@app.route('/pick_real_temp',methods=['GET','POST'])
def pick_real_temp():
	user = session['user']
	if user is None:
		return redirect(url_for('get_username_index'))
	session['user'] = user
	return render_template('pick_draft.html',user=user)

@app.route('/get_pick_draft',methods=['GET','POST'])
def get_pick_draft():
	user = session['user']
	pock=request.form['picking']
	if (pock is None or int(pock) < 1 or int(pock) > 10):
		return render_template("pick_draft.html")
	else:
		session['pock'] = pock
		return render_template("start_draft.html",pock=pock)

@app.route('/draft_temp',methods=['GET','POST'])
def draft_temp():
        pock = int(session['pock'])
	username = session['user'] 
        iter = 1
        teamList = []
        for t in range(10):
                teamList.append([])
        tplayers = playerdefs.setDustyValues(username,pock,playerdefs.setValues(pock,playerdefs.getList(username)),teamList[pock-1])
        players = playerdefs.setSelfie(tplayers)
        if int(pock) == int(iter):
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
	username = session['user'] 
	iter = int(request.form["iter"])
	chosen = int(request.form["chosen"])
	tList = request.form["teams"]
	pList = request.form["players"]
	teamList = playerdefs.tLister(tList)
	players = playerdefs.pLister(pList)
	mypick = fundefs.returnPlayer(chosen,players)
	players.remove(mypick)
	mypick.setPicked(iter)
	teamList[fundefs.getTeam(iter)-1].append(mypick)
	iter+=1
	if int(pock) == int(iter):
		tteam = teamList
		players = playerdefs.setDustyValues(username,pock,players,tteam[pock-1])
		tplayers = sorted(players,key=playerdefs.getKeyD)
	else:
		tteam = teamList
		players = playerdefs.setDustyValues(username,pock,players,tteam[pock-1])
		tplayers = sorted(players,key=playerdefs.getKeyMC)
	
	round = int(iter-1)/10 + 1
	players=[e.serialize() for e in tplayers]
	team = []
	for lop in tteam:
		team.append([e.serialize() for e in lop])
	return jsonify(iter=iter,round=round,team=team,players=players)


#***************************************Set Values***************************

@app.route('/set_values',methods=['GET','POST'])
def set_values():
	user = session['user']
	if user is None:
		return redirect(url_for('get_username_index'))
	session['user'] = user
	return render_template('myVal.html',user=user)

@app.route('/load_vals',methods=['GET','POST'])
def load_vals():
	username = ''
	outAr = playerdefs.getPosVals(username)
	outPlayers = playerdefs.getOutPlayers(username)
	qb = outAr['QB'][0:3]
	rb = outAr['RB'][0:6]
	wr = outAr['WR'][0:6]
	te = outAr['TE'][0:2]
	k = outAr['K'][0:1]
	de = outAr['DE'][0:2]
	return jsonify(players=outPlayers,qb=qb,rb=rb,wr=wr,te=te,k=k,de=de)

@app.route('/save_myAdj',methods=['GET','POST'])
def save_myAdj():
	playerdefs.saveAdj(username,request.form['player'],float(request.form['myadjust']),float(request.form['dpoints']))
	outPlayers = playerdefs.getOutPlayers(username)
	return jsonify(players=outPlayers)

@app.route('/save_posVals',methods=['GET','POST'])
def save_posVals():
	username = session['user']
	playerdefs.savePosVals(username,request.form['values'])
	outPlayers = playerdefs.getOutPlayers(username)
	return jsonify(players=outPlayers,qb=qb,rb=rb,wr=wr,te=te,k=k,de=de)
