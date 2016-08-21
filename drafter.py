from array import array
import scipy
import numpy
import matplotlib.pyplot as plt
import readline
from math import exp
import pymysql.cursors

COMMANDS=[]
playerTeam=[]
npos=[]
mypicks=[]
List = ["QB","RB","WR","TE","K","DE"]

norm = {}
rets = []

norm['QB'] = [5.0,0.0,0,0,0,0]
norm['RB'] = [9.5,9.0,3.0,3.0,2.0,1.0]
norm['WR'] = [8.0,7.5,7.0,4.0,2.0,1.0]
norm['TE'] = [6.0,0.3,0,0,0,0]
norm['K']  = [2.0,0,0,0,0,0]
norm['DE'] = [1.5,0,0,0,0,0]

#qb_low = [8.0,0.5,0,0,0,0]
#rb_low = [10,8.0,7.0,3.0,2.0,1.0]
#wr_low = [8.7,8.5,7.0,3.0,2.0,1.0]
#te_low = [8.0,0.3,0,0,0,0]
#k_low  = [1.0,0,0,0,0,0]
#de_low = [1.5,0,0,0,0,0]

qb_ratio = 5.88 
rb_ratio = 2.0
wr_ratio = 2.0
te_ratio = 7.69
k_ratio  = 10
de_ratio = 10
#qb_ratio = 100.0/17.0
#rb_ratio = 100.0/50.0
#wr_ratio = 100.0/50.0
#te_ratio = 100.0/13.0
#k_ratio  = 100.0/10.0
#de_ratio = 100.0/10.0

vals = {'QB':{'pyards':0.04,'ptds':4,'pints':-2,'ryards':0.1,'rtds':6,'fumbles':-2},'RB':{'ryards':0.1,'rtds':6,'recyards':0.1,'rectds':6,'fumbles':-2},'WR':{'ryards':0.1,'rtds':6,'recyards':0.1,'rectds':6,'fumbles':-2},'TE':{'recyards':0.1,'rectds':6,'fumbles':-2},'K':{'fg':3.33,'xpt':1},'DE':{'ranker':12,'intercept':147,'slope':5.0}}
QB_vals = {'pyards':0.04,'ptds':4,'pints':-2,'ryards':0.1,'rtds':6,'fumbles':-2}
#RB_vals = {'RB':{'ryards':0.1,'rtds':6,'recyards':0.1,'rectds':6,'fumbles':-2},'WR':{'ryards':0.1,'rtds':6,'recyards':0.1,'rectds':6,'fumbles':-2},'TE':{'recyards':0.1,'rectds':6,'fumbles':-2},'K':{'fg':3.33,'xpt':1},'DE':{'ranker':12,'intercept':147,'slope':5.0}}

maxPos = {}

#maxPos = {'QB':0,'RB':0,'WR':0,'TE':0,'K':0,'DE':0}

def initial():
	global npos
	global pick
	global rets
	pick = 11
	del playerTeam[:]
	del mypicks[:]
	del npos[:]
	del COMMANDS[:]
	del rets[:]
	connection = pymysql.connect(host='67.161.161.203',
                             port=3306,
                             user='dstolp',
                             password='ILikeToBrew!14',
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
#rets={**dir_qb,**dir_rb,**dir_wr,**dir_te,**dir_k,**dir_de}
		rets=dir_qb + dir_rb + dir_wr + dir_te + dir_k + dir_de
	#rets=dir_qb

	while pick > 10:
		pick = int(raw_input('Where are you picking (1-10)?\n\t'))
	print "you're picking "+str(pick)
	for i in range(1,151):
		if ((i % 20) == pick) or (((21-i)%20) == pick):
			mypicks.append(i)
			#print "pick is yours "+str(i)
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

def isMyPick(inter):
	mine = False
	for pick in mypicks:
		if pick==inter:
			mine = True
	return mine

def points(play):
	global vals
	pos = play['position']
	points = 0
	mime = []
	if pos in 'DE':
		myadj = [float(play['worst_rank']),float(play['average']),float(play['best_rank'])]
		for ad in myadj:
			if float(play['average']) < vals['DE']['ranker']:
				points = (vals['DE']['intercept']-float(ad))*vals['DE']['slope']
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

#	if play['myadj'] == 2.0:
		#high
#		print play['player']+"\t"+str(points)
#	if play['myadj'] == 1.0:
		#medium
#		if pos in 'DE':
#			if float(play['average']) < vals['DE']['ranker']:
#				points = (vals['DE']['intercept']-float(play['average']))*vals['DE']['slope']
#			else:
#				points = 120
#		else:
#			for pp in vals[pos]:
#				pointer = float(str(play[pp]).replace(',',''))*float(vals[pos][pp])
#				points += float(pointer)
#	if play['myadj'] == 0.0:
		#low
#		if pos in 'DE':
#			if float(play['average']) < DE_vals['ranker']:
#				points = (vals['DE']['intercept']-float(play['worst_rank']))*vals['DE']['slope']
#			else:
#				points = 120
#		else:
#			for pp in vals[pos]:
#				pop = pp+'_low'
#				pointer = float(str(play[pop]).replace(',',''))*float(vals[pos][pp])
#				points += float(pointer)
#	return points

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
#	@classmethod
	def setValue(self,ran):
		self.value = ran
	def setSelfRank(self,ran):
		self.selfrank = ran

def makeList():
	for leng in rets:
		point = points(leng)
		COMMANDS.append(Player(leng['player'].replace(' ','').replace("'",""),leng['team'],leng['bye_week'],leng['position'],leng['adp'],leng['prorank'],point[0],point[1],point[2],leng['myadj']))

def Pickle(pit):
	dustyValue()
	found = False
	readline.parse_and_bind("tab: complete")
	readline.set_completer(complete)
	name = raw_input('Pick '+str(pit)+' is: ')
	for p in COMMANDS:
		if name in  p.name:
			found = True
			npos[teamPick(pit)-1][p.position]+=1
			COMMANDS.remove(p)
			playerTeam[teamPick(pit)-1].append(p)
	if found is False:
		print "Player "+name+" not available"
                Pickle(pit)

def rankpoints(player):
	#value = 0.02*(80-float(player.rank))
	value = 2*exp(-float(player.rank)/5)
	return value

def dustyValue():
        global COMMANDS
	global pick
	tempy = COMMANDS
        for player in tempy:
		lister = [player.lowpoints,player.points,player.highpoints]
                player.setValue(lister[player.myadj]*norm[player.position][npos[pick-1][player.position]]/float(maxPos[player.position])+rankpoints(player))
	COMMANDS = sorted(tempy,key=getKeyD)

def dustyout():
	dustyValue()
	nplayer=0
	outputdusty = []
	for player in COMMANDS:
		nplayer+=1
		if nplayer>20:
			continue
		outputdusty.append({'name':player.name,'value':player.value,'adp':float(player.adp)})
	return outputdusty

def adpout():
	dummy = sorted(COMMANDS,key=getKeyMC)
	nplayer=0
	outputadp = []
	for play in dummy:
		nplayer+=1
		if nplayer>20:
			continue;
		outputadp.append({'name':player.name,'value':player.value,'adp':float(player.adp)})
	return outputadp


def drafting(picking)
	initial(picking)
	for it in range(1,151):
		print str(it)+"\tteam "+str(teamPick(it))
		#if isMyPick(it) is True:
		if teamPick(it) is picking:
			moduleout()
				#print "\tMy rank: "+str(nplayer)+"\tName: "+player.name+"\tPoints: "+str(player.value)+"\tPosition: "+player.position+"\tADP: "+str(float(player.adp))+"\tRank: "+str(float(player.rank))+"\tmy Low Point: "+str(player.lowpoints)+"\tPoints: "+str(player.points)+"\tmy High Point: "+str(player.highpoints)
		else:
							print "\t"+play.name+"\t"+str(play.adp)
		Pickle(it)
