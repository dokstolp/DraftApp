from bs4 import BeautifulSoup
import requests
import csv

teams = {'Houston Texans':'HST','Denver Broncos':'DEN',
        'Seattle Seahawks':'SEA','Kansas City Chiefs':'KC',
        'Minnesota Vikings':'MIN','Carolina Panthers':'CAR',
        'Baltimore Ravens':'BAL','Arizona Cardinals':'ARI',
        'New England Patriots':'NE','Jacksonville Jaguars':'JAC',
        'Pittsburgh Steelers':'PIT','New York Giants':'NYG',
        'Los Angeles Rams':'LAR','Philadelphia Eagles':'PHI',
        'Oakland Raiders':'OAK','Cincinnati Bengals':'CIN',
        'Green Bay Packers':'GB','Los Angeles Chargers':'LAC',
        'Atlanta Falcons':'ATL','Tampa Bay Buccaneers':'TB',
        'Miami Dolphins':'MIA','Buffalo Bills':'BUF',
        'New York Jets':'NYJ','Tennessee Titans':'TEN',
        'Dallas Cowboys':'DAL','Detroit Lions':'DET',
        'Washington Redskins':'WAS','New Orleans Saints':'NO',
        'Indianapolis Colts':'IND','Chicago Bears':'CHI',
        'San Francisco 49ers':'SF','Cleveland Browns':'CLE'
}

# urls for fantasy expert predictions 
url = {'qb':"https://www.fantasypros.com/nfl/projections/qb.php?max-yes=true&min-yes=true&scoring=STD&week=draft",
       'rb':"https://www.fantasypros.com/nfl/projections/rb.php?max-yes=true&min-yes=true&scoring=STD&week=draft",
       'wr':"https://www.fantasypros.com/nfl/projections/wr.php?max-yes=true&min-yes=true&scoring=STD&week=draft",
       'te':"https://www.fantasypros.com/nfl/projections/te.php?max-yes=true&min-yes=true&scoring=STD&week=draft",
       'k':"https://www.fantasypros.com/nfl/projections/k.php?max-yes=true&min-yes=true&scoring=STD&week=draft",
}

# write the xls for backup
def write_xls(players,pos):
	with open("data/"+pos+".xls", "wb") as f:
		writer = csv.writer(f)
		writer.writerows(players)

# get player information according to the position
def get_player(url,pos):
	soup = BeautifulSoup(requests.get(url).text,'html.parser')
	position = []
	for i in soup.findAll('tr',attrs={'class':lambda L: L and L.startswith('mpb-player')}):
		temp = []
		values = i.findAll('td')
		iter = 0
		for val in values:
			iter+=1
			player = val.findAll('a')
			if len(player)>0:
				for inside in player[:1]:
					temp.append(inside.text)
			medhighlow = val.findAll('div')
			midtime = val.text
			for l in medhighlow:
				midtime = midtime.replace(l.text,'',1)
			temp.append(midtime.replace(',',''))    
			if iter>1:
				temp.append(medhighlow[0].text.replace(',',''))
				temp.append(medhighlow[1].text.replace(',',''))
		temp[1] = temp[1].replace(temp[0]+' ','').replace(' highlow','')         
		position.append(temp)
	write_xls(position,pos)

# get players rank
def get_rank():
	url = "https://www.fantasypros.com/nfl/rankings/consensus-cheatsheets.php"
	soup = BeautifulSoup(requests.get(url).text,'html.parser')
	playrank = []
	for i in soup.findAll('tr',attrs={'class':lambda L: L and L.startswith('mpb-player')}):
	        temp = []
	        values = i.findAll('td')
	        for val in values[:9]:
			player = val.findAll('small') + val.findAll('a')
			if len(player)>0:
				for inside in player[:2]:
					temp.append(inside.text)
			else:
			        if len(val.text) ==0:
					temp.append('250.0')
			        else:
					temp.append(val.text)
		temp[3] = ''.join([i for i in temp[3] if not i.isdigit()])
	        if temp[3]=='DST':
			temp[2] = temp[3]
			temp[3] = teams[temp[1]]
	        else:
			team = temp[1]
			temp[1] = temp[2]
			temp[2] = temp[3]
			temp[3] = team
		playrank.append(temp)
	write_xls(playrank,'rank')

# defense has a unique evaluation, so the data is of a different form than the players
def get_def():
	url = "https://www.fantasypros.com/nfl/rankings/dst-cheatsheets.php"
	sde = BeautifulSoup(requests.get(url).text,'html.parser')
	playde = []
	for i in sde.findAll('tr',attrs={'class':lambda L: L and L.startswith('mpb-player')}):
		temp = []
		values = i.findAll('td')
		for val in values[:8]:
			player = val.findAll('small') + val.findAll('a')
			if len(player)>0:
				for inside in player[:2]:
					temp.append(inside.text)
			else:
		        	if len(val.text) ==0:
					temp.append('25.0')
		    		else:
					temp.append(val.text)
		temp[2] = teams[temp[1]]
		playde.append(temp)
	write_xls(playde,'def')

# main and writer
def main():
	for pos in url:
		get_player(url[pos],pos)
	get_rank()
	get_def()

if __name__ == "__main__":
	main()
