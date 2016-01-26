from array import array
#import scipy
#import numpy
#import matplotlib.pyplot as plt
#import readline
from math import exp
import pymysql.cursors
import random

COMMANDS=[]
playerTeam=[]
npos=[]
List = ["QB","RB","WR","TE","K","DE"]

maxpos = {'QB':[1,2],'RB':[3,4],'WR':[3,5],'TE':[1,2],'K':[1,2],'DE':[1,1]}

norm = {}
rets = []

norm['QB'] = [3.0,0.5,0,0,0,0]
norm['RB'] = [10.,9.5,9.0,8.0,4.0,1.0,1.0,0.5,0.5,0.5]
norm['WR'] = [8.7,8.0,8.0,7.5,5.0,1.0,1.0,0.5,0.5,0.5]
norm['TE'] = [8.5,0.3,0,0,0,0]
norm['K']  = [0.5,0,0,0,0,0]
norm['DE'] = [0.5,0,0,0,0,0]


qb_ratio = 5.88 
rb_ratio = 2.0
wr_ratio = 2.0
te_ratio = 7.69
k_ratio  = 10
de_ratio = 10

vals = {'QB':{'pyards':0.04,'ptds':4,'pints':-2,'ryards':0.1,'rtds':6,'fumbles':-2},'RB':{'ryards':0.1,'rtds':6,'recyards':0.1,'rectds':6,'fumbles':-2},'WR':{'ryards':0.1,'rtds':6,'recyards':0.1,'rectds':6,'fumbles':-2},'TE':{'recyards':0.1,'rectds':6,'fumbles':-2},'K':{'fg':3.33,'xpt':1},'DE':{'ranker':12,'intercept':147,'slope':5.0}}
QB_vals = {'pyards':0.04,'ptds':4,'pints':-2,'ryards':0.1,'rtds':6,'fumbles':-2}

maxPos = {}

lamb = 0

def initial(picker,lam):
	global npos
	global pick
	global rets
	global lamb
	pick = 11
	del playerTeam[:]
	del npos[:]
	del COMMANDS[:]
	del rets[:]
	lamb = float(lam)
	connection = pymysql.connect(host='',
                             port=3306,
                             user='',
                             password='',
                             db='NFL_Draft',
                             charset='utf8mb4',
                             cursorclass=pymysql.cursors.DictCursor)

	with connection.cursor() as cursor:
		sqlqb = "SELECT `player`, `team`, `position`, `pyards`, `pyards_low`, `pyards_high`, `ptds`, `ptds_low`, `ptds_high`, `pints`, `pints_low`, `pints_high`, `ryards`, `ryards_low`, `ryards_high`, `rtds`, `rtds_low`, `rtds_high`, `fumbles`, `fumbles_low`, `fumbles_high`, `prorank`, `adp`, `myadj`, `mydp`, `bye_week` FROM `qb_xls`;"
		sqlrb = "SELECT `player`, `team`, `position`, `ryards`, `ryards_low`, `ryards_high`, `rtds`, `rtds_low`, `rtds_high`, `recyards`, `recyards_low`, `recyards_high`, `rectds`, `rectds_low`, `rectds_high`, `fumbles`, `fumbles_low`, `fumbles_high`, `prorank`, `adp`, `myadj`,`mydp`, `bye_week` FROM `rb_xls`;"
		sqlwr = "SELECT `player`, `team`, `position`, `ryards`, `ryards_low`, `ryards_high`, `rtds`, `rtds_low`, `rtds_high`, `recyards`, `recyards_low`, `recyards_high`, `rectds`, `rectds_low`, `rectds_high`, `fumbles`, `fumbles_low`, `fumbles_high`, `prorank`, `adp`, `myadj`,`mydp`, `bye_week` FROM `wr_xls`;"
		sqlte = "SELECT `player`, `team`, `position`, `recyards`, `recyards_low`, `recyards_high`, `rectds`, `rectds_low`, `rectds_high`, `fumbles`, `fumbles_low`, `fumbles_high`, `prorank`, `adp`, `myadj`, `mydp`,`bye_week` FROM `te_xls`;"
		sqlk = "SELECT `player`, `team`, `position`, `fg`, `fg_low`, `fg_high`, `xpt`, `xpt_low`, `xpt_high`, `prorank`, `adp`, `myadj`,`mydp`, `bye_week` FROM `k_xls`;"
		sqlde = "SELECT `player`, `team`, `position`, `best_rank`, `worst_rank`, `average`, `std_dev`, `adp`, `prorank`, `myadj`,`mydp`, `bye_week` FROM `de_xls`;"
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
	pick=int(picker)
	for tea in range (10):
                playerTeam.append([])
                npos.append({})
                for position in List:
                        npos[tea][position] = 0
	makeList()
	setMaxs()
	dustyValue()
	plb=0
	for play in COMMANDS:
		plb+=1
		play.setSelfRank(plb)

def points(play):
	global vals
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

def teamPick(i):
        if (i%20)<=10 and (i%20)>0:
		return i%20
	else:
		return (21-i)%20

def getKeyP(player):
	return -player.points
def getKeyD(player):
	return -player.value

def getKeyMC(player):
	if player.adp>0:
        	return float(player.adp)
	else:
		return 230

def setMaxs():
	global maxPos
	dummy = sorted(COMMANDS,key=getKeyP)
	for pos in List:
		for dum in dummy:
			if dum.position in pos:
				maxPos[pos] = dum.points
				break

class Player(object):
	def __init__(self, name, team, bye, position, adp, rank, low, med, high, myadj):
        	self.name = name
		self.team = team
		self.bye = bye
		self.position = position
		self.points = points
		self.adp = adp
		self.rank = rank
		self.lowpoints = low
		self.points = med
		self.highpoints = high
		self.myadj = int(myadj)
		self.value = 0
		self.selfrank = 0
		self.picked = 0
		self.dpoints = 0
		self.upoints = 0
#	@classmethod
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


def makeList():
	for leng in rets:
		point = points(leng)
		COMMANDS.append(Player(leng['player'],leng['team'],leng['bye_week'],leng['position'],leng['adp'],leng['prorank'],leng['mydp']+point[0],leng['mydp']+point[1],leng['mydp']+point[2],leng['myadj']))

def Pickle(pit):
	dustyValue()
	found = False

def rankpoints(player):
	value = 2.2*exp(-float(player.rank)/5)
	return value

def dustyValue():
        global COMMANDS
	global pick
	tempy = COMMANDS
        for player in tempy:
		difflow = (player.points-player.lowpoints)
		diffhigh = (player.highpoints-player.points)
                lister = [player.lowpoints-difflow,player.lowpoints,player.lowpoints+difflow/2,player.points,player.points+diffhigh/2, player.highpoints, player.highpoints+diffhigh]
#		0:very low, 1:low, 2:little low, 3:middle, 4:little high, 5:high, 6:very high
		player.setValue(lister[player.myadj]*norm[player.position][npos[pick-1][player.position]]/float(maxPos[player.position])+rankpoints(player))
		player.setUpoints(lister[player.myadj])
		player.setDpoints(float(maxPos[player.position])-player.upoints)
	COMMANDS = sorted(tempy,key=getKeyD)

def dustyout():
	dustyValue()
	nplayer=0
	outputdusty = []
	for player in COMMANDS:
		nplayer+=1
		if nplayer>100:
			continue
		outputdusty.append(player)
	return outputdusty

def adpout():
	dummy = sorted(COMMANDS,key=getKeyMC)
	nplayer=0
	outputadp = []
	for player in dummy:
		nplayer+=1
		if nplayer>100:
			continue;
		outputadp.append(player)
	return outputadp

def player_picked(player,itera):
	for play in COMMANDS:
		if player in play.name:
			play.setPicked(itera)
        		npos[teamPick(itera)-1][play.position]+=1
			COMMANDS.remove(play)
			return play

def darank():
	global lamb
	if lamb == 0:
		val = 0
	else:
		val = int(random.expovariate((lamb/5)))
	return val

def autoPick(arank,itera):
        global npos
	tnum = teamPick(itera)-1
        move = 0
	arank +=darank()
        dummy = sorted(COMMANDS,key=getKeyMC)
	if arank >= len(dummy):
		arank = 0
        player = dummy[arank]
        it = 0
        for position in List:
                it += npos[tnum][position]
	
        if it >=9:
                move = 1
        isFlex = (player.position in "RB" or player.position in "WR")
        can = (npos[tnum][player.position]<maxpos[player.position][move])
        needFlex = (npos[tnum]["RB"]+npos[tnum]["WR"]<maxpos["RB"][move]+maxpos["WR"][move]-1)
        if can and (not isFlex or (isFlex and needFlex)):
                playerPicked(tnum,player,itera)
		return player
        else:
                templay = autoPick(arank+1,itera)
		return templay

def autoReturn(arank,itera):
	playa = autoPick(arank,itera)
	arank = 0
	return playa


def playerPicked(tnum,player,itera):
        playerTeam[tnum].append(player)
        npos[tnum][player.position]+=1
	player.setPicked(itera)
        COMMANDS.remove(player)

def myPick(itera):
        dustyValue()
        player = COMMANDS[0]
        npos[pick-1][player.position]+=1
        playerTeam[pick-1].append(player)
        COMMANDS.remove(player)

teamNames = []
def teams():
	global teamNames
	del teamNames[:]
	for r in range(10):
		teamNames.append({'name':"Team "+str(r+2)})
	return teamNames

def drafting(picking):
	for it in range(1,151):
		if teamPick(it) is picking:
			myPick()
		else:
			autopick(0,it)
