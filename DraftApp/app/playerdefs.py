from array import array
from math import exp
import pymysql.cursors
import random
import fundefs
import ast


List = ["QB","RB","WR","TE","K","DE"]

maxpos = {'QB':[1,2],'RB':[3,4],'WR':[3,5],'TE':[1,2],'K':[1,2],'DE':[1,1]}

#norm = {}
#norm['QB'] = [3.0,0.5,0,0,0,0]
#norm['RB'] = [10.,9.5,9.0,8.0,4.0,1.0,1.0,0.5,0.5,0.5]
#norm['WR'] = [8.7,8.0,8.0,7.5,5.0,1.0,1.0,0.5,0.5,0.5]
#norm['TE'] = [8.5,0.3,0,0,0,0]
#norm['K']  = [0.5,0,0,0,0,0]
#norm['DE'] = [0.5,0,0,0,0,0]

vals = {'QB':{'pyards':0.04,'ptds':4,'pints':-2,'ryards':0.1,'rtds':6,'fumbles':-2},'RB':{'ryards':0.1,'rtds':6,'recyards':0.1,'rectds':6,'fumbles':-2},'WR':{'ryards':0.1,'rtds':6,'recyards':0.1,'rectds':6,'fumbles':-2},'TE':{'recyards':0.1,'rectds':6,'fumbles':-2},'K':{'fg':3.33,'xpt':1},'DE':{'ranker':12,'intercept':147,'slope':5.0}}

class Player(object):
        def __init__(self, name, team, bye, position, adp, rank, low, med, high, myadj, mydp, idrank, value=0, selfrank=0, picked=0, dpoints=0, upoints=0):
                self.name = name
                self.team = team
                self.bye = bye
                self.position = position
                self.adp = adp
                self.rank = rank
                self.lowpoints = low
                self.points = med
                self.highpoints = high
                self.myadj = int(myadj)
                self.value = value
                self.selfrank = selfrank
                self.picked = picked
                self.dpoints = dpoints
                self.upoints = upoints
		self.mydp = mydp
		self.idrank = idrank
        def setValue(self,ran):
                self.value = ran
        def setSelfRank(self,ran):
                self.selfrank = ran
        def setPicked(self,picked):
                self.picked = picked
        def setDpoints(self,dpt):
                self.dpoints = dpt
        def setUpoints(self,upt):
                self.upoints = upt
	def serialize(self):
		return {'name':self.name, 
		'team':self.team, 
		'bye':self.bye, 
		'position':self.position, 
		'adp':self.adp, 
		'rank':self.rank,
		'lowpoints':self.lowpoints,
		'points':self.points,
		'highpoints':self.highpoints,
		'myadj':self.myadj,
		'mydp':self.mydp,
		'idrank':self.idrank,
		'value':self.value,
		'selfrank':self.selfrank,
		'picked':self.picked,
		'dpoints':self.dpoints,
		'upoints':self.upoints
		}

def playerList():
	rets = []
        connection = pymysql.connect(host='localhost',
        #connection = pymysql.connect(host='67.161.161.203',
                                     port=3306,
                                     user='dstolp',
                                     password='ILikeToBrew!14',
                                     db='NFL_Draft',
                                     charset='utf8mb4',
                                     cursorclass=pymysql.cursors.DictCursor)

        with connection.cursor() as cursor:
                sqlqb = "SELECT `player`, `team`, `position`, `pyards`, `pyards_low`, `pyards_high`, `ptds`, `ptds_low`, `ptds_high`, `pints`, `pints_low`, `pints_high`, `ryards`, `ryards_low`, `ryards_high`, `rtds`, `rtds_low`, `rtds_high`, `fumbles`, `fumbles_low`, `fumbles_high`, `prorank`, `adp`, `myadj`,  `mydp`, `rank`,`bye_week` FROM `qb_xls`;"
                sqlrb = "SELECT `player`, `team`, `position`, `ryards`, `ryards_low`, `ryards_high`, `rtds`, `rtds_low`, `rtds_high`, `recyards`, `recyards_low`, `recyards_high`, `rectds`, `rectds_low`, `rectds_high`, `fumbles`, `fumbles_low`, `fumbles_high`, `prorank`, `adp`, `myadj`,`mydp`,`rank`, `bye_week` FROM `rb_xls`;"
                sqlwr = "SELECT `player`, `team`, `position`, `ryards`, `ryards_low`, `ryards_high`, `rtds`, `rtds_low`, `rtds_high`, `recyards`, `recyards_low`, `recyards_high`, `rectds`, `rectds_low`, `rectds_high`, `fumbles`, `fumbles_low`, `fumbles_high`, `prorank`, `adp`, `myadj`,`mydp`,`rank`, `bye_week` FROM `wr_xls`;"
                sqlte = "SELECT `player`, `team`, `position`, `recyards`, `recyards_low`, `recyards_high`, `rectds`, `rectds_low`, `rectds_high`, `fumbles`, `fumbles_low`, `fumbles_high`, `prorank`, `adp`, `myadj`, `mydp`,`rank`,`bye_week` FROM `te_xls`;"
                sqlk = "SELECT `player`, `team`, `position`, `fg`, `fg_low`, `fg_high`, `xpt`, `xpt_low`, `xpt_high`, `prorank`, `adp`, `myadj`,`mydp`,`rank`, `bye_week` FROM `k_xls`;"
                sqlde = "SELECT `player`, `team`, `position`, `best_rank`, `worst_rank`, `average`, `std_dev`, `adp`, `prorank`, `myadj`,`mydp`, `rank`,`bye_week` FROM `de_xls`;"
                cursor.execute(sqlqb)
		dir_qb = cursor.fetchall()
                cursor.execute(sqlrb)
                dir_rb = cursor.fetchall()
                cursor.execute(sqlwr)
                dir_wr = cursor.fetchall()
                cursor.execute(sqlte)
                dir_te = cursor.fetchall()
                cursor.execute(sqlk)
                dir_k = cursor.fetchall()
                cursor.execute(sqlde)
                dir_de = cursor.fetchall()
                rets=dir_qb + dir_rb + dir_wr + dir_te + dir_k + dir_de
	connection.close()
        return rets

def getKeyD(player):
        return -player.value

def getKeyMC(player):
        if player.adp>0:
                return float(player.adp)
        else:
                return 230

def getPoints(play):
        pos = play['position']
        points = 0
        mime = []
        if pos in 'DE':
                myadj = [float(play['worst_rank']),float(play['average']),float(play['best_rank'])]
                for ad in myadj:
                        if float(play['average']) < vals['DE']['ranker']:
                                points = (vals['DE']['ranker']-float(ad))*vals['DE']['slope']+vals['DE']['intercept']
                        else:
                                points = 120
                        mime.append(points)
        else:
                addit = ["_low","","_high"]
                for ad in addit:
                        points = 0
                        for pp in vals[pos]:
                                pop = pp+ad
                                pointer = float(str(play[pop]).replace(',',''))*float(vals[pos][pp])
                                points += float(pointer)
                        mime.append(points)
        return mime

def pLister(rets):
	temps = ast.literal_eval(rets)
	allPlayers = []
	for leng in temps:
                allPlayers.append(Player(leng['name'],leng['team'],leng['bye'],leng['position'],int(leng['adp']),int(leng['rank']),leng['lowpoints'],leng['points'],leng['highpoints'],leng['myadj'],leng['mydp'],leng['rank'],leng['value'],leng['selfrank'],leng['picked'],leng['dpoints'],leng['upoints']))
	return allPlayers

def tLister(rets):
	temps = ast.literal_eval(rets)
	allTeams = []
	p=0
	for team in temps:
		allTeams.append([])
		for leng in team:
               		allTeams[p].append(Player(leng['name'],leng['team'],leng['bye'],leng['position'],leng['adp'],leng['rank'],leng['lowpoints'],leng['points'],leng['highpoints'],leng['myadj'],leng['mydp'],leng['rank'],leng['value'],leng['selfrank'],leng['picked'],leng['dpoints'],leng['upoints']))
		p+=1
	return allTeams

def getList():
	allPlayers = []
        rets = playerList()
        for leng in rets:
                point = getPoints(leng)
                allPlayers.append(Player(leng['player'],leng['team'],leng['bye_week'],leng['position'],leng['adp'],leng['prorank'],leng['mydp']+point[0],leng['mydp']+point[1],leng['mydp']+point[2],leng['myadj'],leng['mydp'],leng['rank']))
	return allPlayers

def setDustyValues(pick,list,mylist):
	tempy = list
	npos = fundefs.getNPos(mylist)
	maxs = fundefs.getMaxs(tempy)
	norm = getPosVals()
	for player in tempy:
		normval = norm[str(player.position)][npos[player.position]]
                player.setValue(player.upoints*normval/float(maxs[player.position])+fundefs.getRankVals(player))
	return tempy


def setValues(pick,list):
        tempy = list
        for player in tempy:
                difflow = (player.points-player.lowpoints)
                diffhigh = (player.highpoints-player.points)
#               0:very low, 1:low, 2:little low, 3:middle, 4:little high, 5:high, 6:very high
                lister = [player.lowpoints-difflow,player.lowpoints,player.lowpoints+difflow/2,player.points,player.points+diffhigh/2, player.highpoints, player.highpoints+diffhigh]
                player.setUpoints(lister[player.myadj+3])
	return tempy

def setSelfie(list):
        withVals = sorted(list,key=getKeyD)
	maxs = fundefs.getMaxs(withVals)
	plb=0
	for player in withVals:
		plb+=1
		player.setSelfRank(plb)
                player.setDpoints(float(maxs[player.position])-player.upoints)
	return withVals


def autoPick(arank,lamb,list,tlist):
        move = 0
        arank +=fundefs.darank(lamb)
        dummy = sorted(list,key=getKeyMC)
        if arank >= len(dummy):
                arank = 0
        player = dummy[arank]
        it = 0
	npos = fundefs.getNPos(tlist)
        for position in List:
                it += npos[position]
        if it >=9:
                move = 1
        isFlex = (player.position in "RB" or player.position in "WR")
        can = (npos[player.position]<maxpos[player.position][move])
        needFlex = (npos["RB"]+npos["WR"]<maxpos["RB"][move]+maxpos["WR"][move]-1)
        if can and (not isFlex or (isFlex and needFlex)):
                return player
        else:
                templay = autoPick(arank+1,lamb,list,tlist)
                return templay

def saveAdj(player,myadjust,dpoints):
        plist = {'QB':'qb_xls','RB':'rb_xls','WR':'wr_xls','TE':'te_xls','K':'k_xls','DE':'de_xls'}
        connection = pymysql.connect(host='localhost',
        #connection = pymysql.connect(host='67.161.161.203',
                                     port=3306,
                                     user='dstolp',
                                     password='ILikeToBrew!14',
                                     db='NFL_Draft',
                                     charset='utf8mb4',
                                     cursorclass=pymysql.cursors.DictCursor)

        with connection.cursor() as cursor:
		position = []
		for table in plist:
			cursor.execute("SELECT `position` FROM "+plist[table]+" WHERE "+plist[table]+".rank = '"+player+"';")
			outList = cursor.fetchall()
			if (len(outList)>0):
				position = outList[0]['position']
				break
		cursor.execute("UPDATE myVals SET value = "+str(myadjust)+" WHERE myVals.rank = '"+str(player)+"';")
		cursor.execute("UPDATE myVals SET dpoints = "+str(dpoints)+" WHERE myVals.rank = '"+str(player)+"';")
		cursor.execute("UPDATE "+str(plist[position])+" SET myadj = "+str(myadjust)+" WHERE "+str(plist[position])+".rank = '"+str(player)+"';")
		cursor.execute("UPDATE "+str(plist[position])+" SET mydp = "+str(dpoints)+" WHERE "+str(plist[position])+".rank = '"+str(player)+"';")
	connection.commit()
	connection.close()



def savePosVals(instring):
        connection = pymysql.connect(host='localhost',
        #connection = pymysql.connect(host='67.161.161.203',
                                     port=3306,
                                     user='dstolp',
                                     password='ILikeToBrew!14',
                                     db='NFL_Draft',
                                     charset='utf8mb4',
                                     cursorclass=pymysql.cursors.DictCursor)

        with connection.cursor() as cursor:
		values = ast.literal_eval(instring)
		qb = values[0:6]
		rb = values[6:16]
		wr = values[16:26]
		te = values[26:32]
		k  = values[32:38]
		de = values[38:44]

		i=0
		for val in qb:
			i+=1
			cursor.execute("UPDATE users SET qb"+str(i)+" = "+str(val)+" WHERE username = 'Dusty';")
		i=0
		for val in rb:
			i+=1
			cursor.execute("UPDATE users SET rb"+str(i)+" = "+str(val)+" WHERE username = 'Dusty';")
		i=0
		for val in wr:
			i+=1
			cursor.execute("UPDATE users SET wr"+str(i)+" = "+str(val)+" WHERE username = 'Dusty';")
		i=0
		for val in te:
			i+=1
			cursor.execute("UPDATE users SET te"+str(i)+" = "+str(val)+" WHERE username = 'Dusty';")
		i=0
		for val in k:
			i+=1
			cursor.execute("UPDATE users SET k"+str(i)+" = "+str(val)+" WHERE username = 'Dusty';")
		i=0
		for val in de:
			i+=1
			cursor.execute("UPDATE users SET de"+str(i)+" = "+str(val)+" WHERE username = 'Dusty';")
	connection.commit()
	connection.close()

def getPosVals():
        connection = pymysql.connect(host='localhost',
        #connection = pymysql.connect(host='67.161.161.203',
                                     port=3306,
                                     user='dstolp',
                                     password='ILikeToBrew!14',
                                     db='NFL_Draft',
                                     charset='utf8mb4',
                                     cursorclass=pymysql.cursors.DictCursor)
        with connection.cursor() as cursor:
#		posVals = "SELECT `qb1`,`qb2`,`qb3`,`qb4`,`qb5`,`qb6`,`rb1`,`rb2`,`rb3`,`rb4`,`rb5`,`rb6`,`rb7`,`rb8`,rb9`,`rb10`,`wr1`,`wr2`,`wr3`,`wr4`,`wr5`,`wr6`,`wr7`,`wr8`,wr9`,`wr10`,`te1`,`te2`,`te3`,`te4`,`te5`,`te6`,`k1`,`k2`,`k3`,`k4`,`k5`,`k6`,`de1`,`de2`,`de3`,`de4`,`de5`,`de6` FROM users WHERE username = 'Dusty';"
		posVals = "SELECT * FROM users WHERE username='Dusty';"
		cursor.execute(posVals)
		posOut = cursor.fetchall()
		#posOut = ast.literal_eval(cursor.fetchall())
		qb = []
		rb = []
		wr = []
		te = []
		k = []
		de = []
		for i in range(1,11):
			rb.append(posOut[0]['rb'+str(i)])
			wr.append(posOut[0]['wr'+str(i)])
			if i>6:
				continue
			qb.append(posOut[0]['qb'+str(i)])
			te.append(posOut[0]['te'+str(i)])
			k.append(posOut[0]['k'+str(i)])
			de.append(posOut[0]['de'+str(i)])
	connection.commit()
	connection.close()
	ret = {'QB':qb,'RB':rb,'WR':wr,'TE':te,'K':k,'DE':de}
	return ret

def getOutPlayers():
	teamList = []
	tplayers = setDustyValues(1,setValues(1,getList()),teamList)
	players = setSelfie(tplayers)
	tplayers=[e.serialize() for e in players]
	return tplayers
