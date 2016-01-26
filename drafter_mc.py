from array import array
import scipy
import numpy
import matplotlib.pyplot as plt
import readline
from math import exp
import pymysql.cursors

COMMANDS=[]
playerTeam = []
npos = []
mypicks = []
pick = 11
List = ["QB","RB","WR","TE","K","DE"]

norm = {}
rets = []

qb1_vals = [5,6]
rb1_vals = [10,9]
rb2_vals = [10,9,8]
wr1_vals = [10,9,8]
wr2_vals = [10,9,8]


norm['QB'] = [5.0,0.0,0,0,0,0]
norm['RB'] = [9.0,9.0,3.0,3.0,2.0,1.0]
norm['WR'] = [8.5,7.5,7.0,4.0,2.0,1.0]
norm['TE'] = [6.0,0.3,0,0,0,0]
norm['K']  = [2.0,0,0,0,0,0]
norm['DE'] = [1.5,0,0,0,0,0]



maxPos = {}
maxpos = {'QB':[1,2],'RB':[3,4],'WR':[3,5],'TE':[1,2],'K':[1,2],'DE':[1,1]}

vals = {'QB':{'pyards':0.04,'ptds':4,'pints':-2,'ryards':0.1,'rtds':6,'fumbles':-2},'RB':{'ryards':0.1,'rtds':6,'recyards':0.1,'rectds':6,'fumbles':-2},'WR':{'ryards':0.1,'rtds':6,'recyards':0.1,'rectds':6,'fumbles':-2},'TE':{'recyards':0.1,'rectds':6,'fumbles':-2},'K':{'fg':3.33,'xpt':1},'DE':{'ranker':12,'intercept':147,'slope':5.0}}


def initial():
	global rets
	connection = pymysql.connect(host='',
			     port=3306,
			     user='',
			     password='',
			     db='NFL_Draft',
			     charset='utf8mb4',
			     cursorclass=pymysql.cursors.DictCursor)
	with connection.cursor() as cursor:
                sqlqb = "SELECT `player`, `team`, `position`, `pyards`, `pyards_low`, `pyards_high`, `ptds`, `ptds_low`, `ptds_high`, `pints`, `pints_low`, `pints_high`, `ryards`, `ryards_low`, `ryards_high`, `rtds`, `rtds_low`, `rtds_high`, `fumbles`, `fumbles_low`, `fumbles_high`, `prorank`, `adp`, `myadj`, `bye_week` FROM `qb_xls`;"
                sqlrb = "SELECT `player`, `team`, `position`, `ryards`, `ryards_low`, `ryards_high`, `rtds`, `rtds_low`, `rtds_high`, `recyards`, `recyards_low`, `recyards_high`, `rectds`, `rectds_low`, `rectds_high`, `fumbles`, `fumbles_low`, `fumbles_high`, `prorank`, `adp`, `myadj`, `bye_week` FROM `rb_xls`;"
                sqlwr = "SELECT `player`, `team`, `position`, `ryards`, `ryards_low`, `ryards_high`, `rtds`, `rtds_low`, `rtds_high`, `recyards`, `recyards_low`, `recyards_high`, `rectds`, `rectds_low`, `rectds_high`, `fumbles`, `fumbles_low`, `fumbles_high`, `prorank`, `adp`, `myadj`, `bye_week` FROM `wr_xls`;"
                sqlte = "SELECT `player`, `team`, `position`, `recyards`, `recyards_low`, `recyards_high`, `rectds`, `rectds_low`, `rectds_high`, `fumbles`, `fumbles_low`, `fumbles_high`, `prorank`, `adp`, `myadj`, `bye_week` FROM `te_xls`;"
                sqlk = "SELECT `player`, `team`, `position`, `fg`, `fg_low`, `fg_high`, `xpt`, `xpt_low`, `xpt_high`, `prorank`, `adp`, `myadj`, `bye_week` FROM `k_xls`;"
                sqlde = "SELECT `player`, `team`, `position`, `best_rank`, `worst_rank`, `average`, `std_dev`, `adp`, `prorank`, `myadj`, `bye_week` FROM `de_xls`;"
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
		
def initialPick(pi):
	global npos
	global pick
	pick = pi
	del playerTeam[:]
	del mypicks[:]
	del npos[:]
	del COMMANDS[:]
        
	for i in range(1,151):
		if ((i % 20) == pick) or (((21-i)%20) == pick):
			mypicks.append(i)
	for tea in range (10):
		playerTeam.append([])
		npos.append({})
		for position in List:
			npos[tea][position] = 0
	makeList()
	setMaxs()
	dustyValue()
	plb = 0
	for play in COMMANDS:
		plb+=1
		play.setSelfRank(plb)

def points(play):
        global vals
        points = 0
        pos = play['position']

        if play['myadj'] == 2.0:
                #high
                if pos in 'DE':
                        if float(play['average']) < DE_vals['ranker']:
                                points = (DE_vals['intercept']-float(play['best_rank']))*DE_vals['slope']
                        else:
                                points = 120
                else:
                        for pp in vals[pos]:
                                pop = pp+'_high'
                                pointer = float(str(play[pop]).replace(',',''))*float(vals[pos][pp])
                                points += float(pointer)
        if play['myadj'] == 1.0:
                #medium
                if pos in 'DE':
                        if float(play['average']) < vals['DE']['ranker']:
                                points = (vals['DE']['intercept']-float(play['average']))*vals['DE']['slope']
                        else:
                                points = 120
                else:
                        for pp in vals[pos]:
                                pointer = float(str(play[pp]).replace(',',''))*float(vals[pos][pp])
                                points += float(pointer)
        if play['myadj'] == 0.0:
                #low
                if pos in 'DE':
                        if float(play['average']) < DE_vals['ranker']:
                                points = (DE_vals['intercept']-float(play['worst_rank']))*DE_vals['slope']
                        else:
                                points = 120
                else:
                        for pp in vals[pos]:
                                pop = pp+'_low'
                                pointer = float(str(play[pop]).replace(',',''))*float(vals[pos][pp])
                                points += float(pointer)
        return points


def teamPick(i):
	if (i%20)<=10 and (i%20)>0:
		return i%20
	else:
		return (21-i)%20

def complete(text, state):
    for cmd in COMMANDS:
        if cmd.name.startswith(text):
            if not state:
                return cmd.name
            else:
                state -= 1

def getKeyP(player):
        return -player.points

def getKeyD(player):
	return -player.value

def getKeyMC(player):
	if player.adp>0:
		return float(player.adp)
	else:
		return 230
def getKeyPos(player):
	return player.position

class Player(object):
	def __init__(self, name, team, bye, position, adp, rank, points):
        	self.name = name
		self.team = team
		self.bye = bye
		self.position = position
		self.adp = adp
		self.rank = rank
		self.points = points
		self.adpvalue = 0
		self.value = 0
		self.selfrank = 0
	def setValue(self,val):
		self.value = val
	def setSelfRank(self,ran):
		self.selfrank = ran
	def setadpValue(self,val):
		self.adpvalue = val

def makeList():
	global rets
        for leng in rets:
		COMMANDS.append(Player(leng['player'].replace(' ','').replace("'",""),leng['team'],leng['bye_week'],leng['position'],leng['adp'],leng['prorank'],points(leng)))

def autoPick(tnum,arank,itera):
	move = 0
	global npos
	dummy = sorted(COMMANDS,key=getKeyMC)
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
		playerPicked(tnum,player)
	else:
		autoPick(tnum,arank+1,itera)


def playerPicked(tnum,player):
	playerTeam[tnum].append(player)
	npos[tnum][player.position]+=1
	COMMANDS.remove(player)

def myPick():
	dustyValue()
	player = COMMANDS[0]
	npos[pick-1][player.position]+=1
	playerTeam[pick-1].append(player)
	COMMANDS.remove(player)

def rankpoints(player):
	value = 2*exp(-float(player.rank)/5)
	return value
	
def setMaxs():
        global maxPos
	global List
	dummy = sorted(COMMANDS,key=getKeyP)
        for pos in List:
                for dum in dummy:
                        if dum.position in pos:
                                maxPos[pos] = dum.points
                                break


def dustyValue():
        global COMMANDS
        global pick
        tempy = COMMANDS
        for player in tempy:
                player.setValue(float(player.points)*norm[player.position][npos[pick-1][player.position]]/float(maxPos[player.position])+rankpoints(player))
        COMMANDS = sorted(tempy,key=getKeyD)

def normalizer(qb1,rb1,rb2,wr1,wr2):
	global norm
	norm['QB'][0] = qb1
	norm['RB'][0] = rb1
	norm['RB'][1] = rb2
	norm['WR'][0] = wr1
	norm['WR'][1] = wr2

def draft(pi):
	initialPick(pi+1)
	pick = pi+1
	playable = []
	mypoints = 0
	mean = 0
	maximum = 0
	iter = 0
	for it in range(1,151):
		if teamPick(it) is pick:
			myPick()
		else:
			autoPick(teamPick(it)-1,0,it)
	for team in range(10):
		points = 0
		myTeam = (pick is team+1)
		for position in List:
			npos[team][position] = 0
		for player in playerTeam[team]:
			if npos[team][player.position]<maxpos[player.position][0]:
				points +=float(player.points)
				npos[team][player.position]+=1
		if not myTeam:
			mean+=points/9.0
		playable.append(points)
	for team in playable:
		if iter is not pi:
			if team > maximum:
				maximum = team
		iter+=1
	tempmean = playable[pi]/mean
	tempmax = playable[pi]/maximum
	temps = [tempmean,tempmax]
	return temps

bestmaxnorms = []
bestmeannorms = []
initial()
for pi in range(10):
	print "\nYou are Picking at position: "+str(pi+1)
	del bestmaxnorms [:]
	del bestmeannorms [:]
	bestmax = 0
	bestmean = 0
	for qb in qb1_vals:
		for rb1 in rb1_vals:
			for rb2 in rb2_vals:
				for wr1 in wr1_vals:
					for wr2 in wr2_vals:
						templist = [qb,rb1,rb2,wr1,wr2]
						normalizer(qb,rb1,rb2,wr1,wr2)
						bells = draft(pi)
						if(bells[0]>bestmean):
							bestmean = bells[0]
							bestmeannorms = templist
						if(bells[1]>bestmax):
							bestmax = bells[1]
							bestmaxnorms = templist

	print "for pick "+str(pi+1)+"\tbest vs max is "+str(bestmaxnorms)+"\twith bestmax: "+str(bestmax)+"\tbest vs mean is "+str(bestmeannorms)+"\twith bestmean: "+str(bestmean)
