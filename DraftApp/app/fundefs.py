from array import array
from math import exp
import pymysql.cursors
import random
from werkzeug.security import generate_password_hash, check_password_hash

List = ["QB","RB","WR","TE","K","DE"]

def getTeam(i):
        if (i%20)<=10 and (i%20)>0:
                return i%20
        else:
                return (21-i)%20

def getRankVals(player):
        #value = 0.02*(80-float(player.rank))
        #value = 2*exp(-float(player.rank)/5)
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

def checkUser(username,password):
        cursor = g.db_conn.cursor()
	cursor.execute("SELECT `password` FROM `users` WHERE username = '"+username+"'")
	passwordhash = cursor.fetchall()
	if len(passwordhash) is 1:
		if check_password_hash(passwordhash[0]['password'], password):				
			return True
	return False
		
def unusedUser(username,email):
        cursor = g.db_conn.cursor()
	selector = "SELECT `username` FROM `users` WHERE username = '"+username+"' OR email = '"+email+"'"
	cursor.execute(selector)
	user = cursor.fetchall()
	apple.append(user)
	if len(apple) > 1:
		return False
	return True

def addUser(username,password,email):
        cursor = g.db_conn.cursor()
	hashed = generate_password_hash(password)
	tableCreator = "CREATE TABLE `myVals"+username+"` (`rank` INT, `player` varchar(255) NOT NULL, `value` float DEFAULT 0, `dpoints` float DEFAULT 0, PRIMARY KEY(`player`)) ENGINE = memory;"
	cursor.execute(tableCreator)
	cursor.execute("INSERT INTO `myVals"+username+"` (player,rank) SELECT player,rank FROM rank_xls;")
	cursor.execute("INSERT INTO `users` (`username`, `password`,`email`) VALUES ('"+username+"','"+hashed+"','"+email+"')");
