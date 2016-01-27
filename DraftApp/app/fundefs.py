from array import array
from math import exp
import pymysql.cursors
import random

List = ["QB","RB","WR","TE","K","DE"]

def getTeam(i):
        if (i%20)<=10 and (i%20)>0:
                return i%20
        else:
                return (21-i)%20

def getRankVals(player):
        value = 2.2*exp(-float(player.rank)/5)
        return value

def getNPos(tlist):
	npos = {}
	for pos in List:
		npos[pos] = 0
        for play in tlist:
		for pos in List:
                	if play.position == pos:
                        	npos[pos]+=1
        return npos

def getMaxs(list):
	pmax = {}
	for pos in List:
		pmax[pos] = 0
        for dum in list:
		for pos in List:
                	if dum.position == pos:
                        	if dum.upoints > pmax[pos]:
					pmax[pos] = dum.upoints
	return pmax

def returnPlayer(play,list):
        for pl in list:
                if int(pl.selfrank) == int(play):
                        return pl

def darank(lamb):
        if lamb == 0:
                val = 0
        else:
                val = int(random.expovariate((float(lamb)/5.)))
        return val