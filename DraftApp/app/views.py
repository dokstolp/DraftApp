from flask import Flask, render_template, request, url_for, redirect, session, jsonify, g
from app import app
import pymysql.cursors
import sys
import playerdefs
import fundefs
import userfuns
import pandas as pd
import numpy as np
from sklearn.externals import joblib
from sklearn.ensemble import RandomForestClassifier

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
                checksOut = userfuns.checkUser(username,password)
                user = username
                if checksOut is True:
                        fname = userfuns.getFirstName(username)
                        session['fname'] = fname
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
        fname = request.form['fname']
        isUnused = userfuns.unusedUser(username,email)
        if isUnused and (password == retype) and (" " not in username) and (" " not in fname):
                user = username
                userfuns.addUser(username,password,email,fname)
                session['user'] = username
                session['fname'] =  fname
                return render_template('homepage.html',user=user,fname=fname)
        else:
                return render_template('newAccount.html')

#****************************************Returning User*******************************
@app.route('/userHomePage',methods=['GET','POST'])
def userHomePage():
        username = session['user']
        fname = session['fname']
        if username is None:
                return redirect(url_for('get_username_index'))
        return render_template('homepage.html',user=username,fname=fname)

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
        fname = session['fname']
        if user is None:
                return redirect(url_for('get_username_index'))
        session['user'] = user
        return render_template('pick_mock.html',user=user,fname=fname)

@app.route('/get_pick_mock',methods=['GET','POST'])
def get_pick_mock():
        user = session['user']
        fname = session['fname']
        pock=request.form['picking']
        lamb=request.form['diff']
        nteams=request.form['nteams']
        session['user'] = user
        if (pock is None or int(pock) < 1 or int(pock) > nteams) or (lamb is None or int(lamb) < 0 or int(lamb) > 10):
                return render_template("pick_mock.html",user=user,fname=fname)
        else:
                session['pock'] = pock
                session['lamb'] = lamb
                session['nteams'] = nteams
                return render_template("start_mock.html",pock=pock,lamb=lamb,nteams=nteams,fname=fname)

@app.route('/mock_temp',methods=['GET','POST'])
def mock_temp():
        pock = int(session['pock'])
        lamb = int(session['lamb'])
        username = session['user']
        nteams = int(session['nteams'])
        iter = 1
        TeamList = []
        for t in range(nteams):
                TeamList.append([])
        allPlayers = playerdefs.getMockPlayers(username,pock,iter,TeamList,0)
        mockedResults = mockery(iter,pock,lamb,allPlayers['outTeams'],allPlayers['players'])
        iter = mockedResults['iter']
        allOutPlayers = mockedResults['players']
        outTeams = mockedResults['team']
        round = int(iter-1)/nteams + 1
        outPlayers = sorted(allOutPlayers,key=fundefs.getKeyD)[:30]
        players = [e.serializeDraft() for e in outPlayers]
        teams = []
        for team in outTeams:
                teams.append([e.serializePicked() for e in team])
        return jsonify(iter=iter,round=round,team=teams,players=players)

@app.route('/mock',methods=['GET','POST'])
def mock():
        pock = int(session['pock'])
        lamb = int(session['lamb'])
        username = session['user']
        iter = int(request.form["iter"])
        chosen = int(request.form["chosen"])
        TeamList = request.form["teams"]
        nteams = len(TeamList)
        allPlayers = playerdefs.getMockPlayers(username,pock,iter,TeamList,chosen)
        iter+=1
        mockedResults = mockery(iter,pock,lamb,allPlayers['outTeams'],allPlayers['players'])
        iter = mockedResults['iter']
        allOutPlayers = mockedResults['players']
        outTeams = mockedResults['team']
        round = int(iter-1)/nteams + 1
        outPlayers = sorted(allOutPlayers,key=fundefs.getKeyD)[:30]
        players = [e.serializeDraft() for e in outPlayers]
        teams = []
        for team in outTeams:
                teams.append([e.serializePicked() for e in team])
        return jsonify(iter=iter,round=round,team=teams,players=players)

def mockery(iter,pock,lamb,teams,players):
        nteams = len(teams)
        while(int(fundefs.getTeam(iter,nteams)) is not int(pock)):
                team = int(fundefs.getTeam(iter,nteams))
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
        fname= session['fname']
        if user is None:
                return redirect(url_for('get_username_index'))
        session['user'] = user
        return render_template('pick_draft.html',user=user,fname=fname)

@app.route('/get_pick_draft',methods=['GET','POST'])
def get_pick_draft():
        user = session['user']
        fname= session['fname']
        pock=request.form['picking']
        nteams=request.form['nteams']
        if (pock is None or int(pock) < 1 or int(pock) > 10 or int(nteams)%2 !=0):
                return render_template("pick_draft.html")
        else:
                session['pock'] = pock
                session['nteams'] = nteams
                session['user'] = user
                return render_template("start_draft.html",user=user,pock=pock,nteams=nteams,fname=fname)

@app.route('/draft_temp',methods=['GET','POST'])
def draft_temp():
        pock = int(session['pock'])
        username = session['user']
        nteams= int(session['nteams'])
        iter = 1
        round = 1
        TeamList = []
        for t in range(nteams):
                TeamList.append([])
        allPlayers = playerdefs.getPlayers(username,pock,iter,TeamList,0)

        players = [e.serializeDraft() for e in allPlayers['players']]
        teams = []
        for team in allPlayers['outTeams']:
                teams.append([e.serializePicked() for e in team])
        return jsonify(iter=iter,round=round,team=teams,players=players)

@app.route('/draft_name',methods=['GET','POST'])
def draft_name():
        pock = int(session['pock'])
        username = session['user']
        iter = int(request.form["iter"])
        chosen = request.form["chosen"]
        TeamList = request.form["teams"]
        nteams = len(TeamList)
        allPlayers = playerdefs.getPlayersName(username,pock,iter,TeamList,chosen)
        found = allPlayers['found']
        if found == False:
                return jsonify(found=found)
        iter+=1
        round = int(iter-1)/nteams + 1
        players = [e.serializeDraft() for e in allPlayers['players']]
        teams = []
        for team in allPlayers['outTeams']:
                teams.append([e.serializePicked() for e in team])
        return jsonify(found=found,iter=iter,round=round,team=teams,players=players)


@app.route('/draft',methods=['GET','POST'])
def draft():
        pock = int(session['pock'])
        username = session['user']
        iter = int(request.form["iter"])
        chosen = int(request.form["chosen"])
        TeamList = request.form["teams"]
        nteams = len(TeamList)
        allPlayers = playerdefs.getPlayers(username,pock,iter,TeamList,chosen)

        iter+=1
        round = int(iter-1)/nteams + 1
        players = [e.serializeDraft() for e in allPlayers['players']]
        teams = []
        for team in allPlayers['outTeams']:
                teams.append([e.serializePicked() for e in team])
        return jsonify(iter=iter,round=round,team=teams,players=players)

#***************************************Set Values***************************

@app.route('/set_values',methods=['GET','POST'])
def set_values():
        user = session['user']
        fname= session['fname']
        if user is None:
                return redirect(url_for('get_username_index'))
        session['user'] = user
        return render_template('myEval.html',user=user,fname=fname)

@app.route('/get_qbeval',methods=['GET','POST'])
def get_qbeval():
        user = session['user']
        fname= session['fname']
        if user is None:
                return redirect(url_for('get_username_index'))
        session['user'] = user
        session['position'] = 'QB'
        return render_template('rankVal.html',user=user,fname=fname,position='QB')

@app.route('/get_rbeval',methods=['GET','POST'])
def get_rbeval():
        user = session['user']
        fname= session['fname']
        if user is None:
                return redirect(url_for('get_username_index'))
        session['user'] = user
        session['position'] = 'RB'
        return render_template('rankVal.html',user=user,fname=fname,position='RB')

@app.route('/get_wreval',methods=['GET','POST'])
def get_wreval():
        user = session['user']
        fname= session['fname']
        if user is None:
                return redirect(url_for('get_username_index'))
        session['user'] = user
        session['position'] = 'WR'
        return render_template('rankVal.html',user=user,fname=fname,position='WR')

@app.route('/get_teeval',methods=['GET','POST'])
def get_teeval():
        user = session['user']
        fname= session['fname']
        if user is None:
                return redirect(url_for('get_username_index'))
        session['user'] = user
        session['position'] = 'TE'
        return render_template('rankVal.html',user=user,fname=fname,position='TE')

@app.route('/get_keval',methods=['GET','POST'])
def get_keval():
        user = session['user']
        fname= session['fname']
        if user is None:
                return redirect(url_for('get_username_index'))
        session['user'] = user
        session['position'] = 'K'
        return render_template('rankVal.html',user=user,fname=fname,position='K')

@app.route('/get_deeval',methods=['GET','POST'])
def get_deeval():
        user = session['user']
        fname= session['fname']
        if user is None:
                return redirect(url_for('get_username_index'))
        session['user'] = user
        session['position'] = 'DE'
        return render_template('rankVal.html',user=user,fname=fname,position='DE')


@app.route('/load_SelVals',methods=['GET','POST'])
def load_SelVals():
        username = session['user']
        position = session['position']
        allPlayers = playerdefs.getSetPlayers(username,position)
        names = allPlayers['allPlayers']
        selplayers = allPlayers['poslist']
        return jsonify(players=names,selPlayers=selplayers,user=username,position=position)

@app.route('/load_PosVals',methods=['GET','POST'])
def load_PosVals():
        username = session['user']
        outAr = userfuns.getPosVals(username)
        qb = outAr['QB'][0:3]
        rb = outAr['RB'][0:6]
        wr = outAr['WR'][0:6]
        te = outAr['TE'][0:2]
        k = outAr['K'][0:1]
        de = outAr['DE'][0:2]
        allPlayers = playerdefs.getSetPlayers(username,'')
        names = allPlayers['allPlayers']
        return jsonify(players=names,qb=qb,rb=rb,wr=wr,te=te,k=k,de=de)

@app.route('/save_myAdj',methods=['GET','POST'])
def save_myAdj():
        username = session['user']
        position = request.form['pos']
        userfuns.saveAdj(username,request.form['player'],request.form['myadjust'],request.form['dpoints'])
        allPlayers = playerdefs.getSetPlayers(username,position)
        names = allPlayers['allPlayers']
        selplayers = allPlayers['poslist']
        return jsonify(players=names,selPlayers=selplayers)

@app.route('/save_posVals',methods=['GET','POST'])
def save_posVals():
        username = session['user']
        outList = userfuns.savePosVals(username,request.form['values'])
        qb = outList['QB']
        rb = outList['RB']
        wr = outList['WR']
        te = outList['TE']
        k = outList['K']
        de = outList['DE']
        allPlayers = playerdefs.getSetPlayers(username,'')
        names = allPlayers['allPlayers']
        return jsonify(players=names,qb=qb,rb=rb,wr=wr,te=te,k=k,de=de)

#***************************************Personal Site***************************

@app.route('/resume',methods=['GET','POST'])
def resume():
        return render_template('resume.html')

#***************************************Slides***************************

@app.route('/slides',methods=['GET','POST'])
def slides():
        return render_template('slides.html')

#***************************************playpredictor***************************

@app.route('/anticiplay',methods=['GET','POST'])
def playpredictor():
	return render_template('playpredictor.html')

@app.route('/prediction',methods=['GET','POST'])
def prediction():
	timeM = request.form['minutes']
	yards = request.form['yards']
	OffTeam = request.form['offense']
	DefTeam = request.form['defense']
	scoreOff = request.form['scoreOff']
	scoreDef = request.form['scoreDef']
	distance = request.form['distance']
	quarter = request.form['quarter']
	down = request.form['down']
	time = time_in_half(quarter,timeM)
	result,errors,low,high = predict(time,int(yards),OffTeam,DefTeam,int(scoreOff),int(scoreDef),int(quarter),int(down),int(distance))
	return jsonify(pre=result,err=errors,low=low,high=high)

def time_in_half(quarter,timeM):
        time_already = ((4-int(quarter))%2)*900
        return time_already + int(timeM)*60

def revProb(mean,low,high):
	bimean = [1-mean,mean]
	bilow =  [1-high,low]
	bihigh = [1-low,high]
	index = int(mean+0.5)
	return (index,bimean[index],bilow[index],bihigh[index])

def predict(time,yards,offT,defT,scoreOff,scoreDef,quarter,down,distance):
	cursor = g.db_conn.cursor()
        retval = ['Run','Pass']
	cursor.execute("SELECT `OffRatio`,`OffPass`,`OffRush` FROM `teams` WHERE `team` = '"+offT+"'")
	offense = cursor.fetchall()
	cursor.execute("SELECT `DefRatio`,`DefPass`,`DefRush` FROM `teams` WHERE `team` = '"+defT+"'")
	defense = cursor.fetchall()
        offRatio= offense[0]['OffRatio']
        offPass = offense[0]['OffPass']
        offRush = offense[0]['OffRush']
	defRatio= defense[0]['DefRatio']
	defPass = defense[0]['DefPass']
	defRush = defense[0]['DefRush']
	mean,low,high = mcpredict(down,distance,scoreOff-scoreDef,time,offRatio,defRatio,yards)
	index,outmean,outlow,outhigh = revProb(mean,low,high)
        return (retval[index],'{:0.2f}'.format(outmean),'{:0.3f}'.format(outlow),'{:0.3f}'.format(outhigh))

def evaluate(dow,dis,sco,tim,off,de,yds,co_int,co_dow,co_dis,co_sco,co_tim,co_off,co_de,co_yds):
        dis_mean = 8.66009839633
        sco_mean = -0.940609689433
        tim_mean = 842.53228023
        off_mean = 1.31796624476
	de_mean = 1.30453080602
	yds_mean = 52.8566305
        dis_std = 3.92317694022
        sco_std = 10.7200225916
        tim_std = 545.837556421
        off_std = 0.266053395821
	de_std = 0.196321660874
	yds_std = 24.7495759082
        v = co_int + co_dow*dow + co_dis*(dis-dis_mean)/dis_std + co_sco*(sco-sco_mean)/sco_std \
                   + co_tim*(tim-tim_mean)/tim_std + co_off*(off-off_mean)/off_std + co_de*(de-de_mean)/de_std \
		   + co_yds*(yds-yds_mean)/yds_std
        return (1/(1+np.exp(-v)))

def mcpredict(down,distance,scorediff,time,offRatio,defRatio,ydstogoal):
	cursor = g.db_conn.cursor()
        cursor.execute("SELECT `intercept`, `Down`, `DistanceReg`, `ScoreDiffReg`, `TimeInHalfReg`, `OffYearRatioReg`, `DefYearRatioReg`, `YardsToGoalReg` FROM `trace`")
        offense = cursor.fetchall()
        values = [evaluate(down,distance,scorediff,time,offRatio,defRatio,ydstogoal,
                          off['intercept'],off['Down'],off['DistanceReg'],off['ScoreDiffReg'],
			  off['TimeInHalfReg'],off['OffYearRatioReg'],off['DefYearRatioReg'],off['YardsToGoalReg']) for off in offense]
	mean = np.mean(values)
        low = np.percentile(values,2.5)
        high =  np.percentile(values,97.5)
	print mean
	return (mean,low,high)
