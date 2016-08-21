from requests import Session

s = Session()
r1 = s.get("https://secure.fantasypros.com/accounts/login/?next=http://www.fantasypros.com/index.php")
csrf_token = r1.cookies['csrftoken']
login_data = {'csrfmiddlewaretoken': csrf_token, 'username':'','password':''}
r = s.post("https://secure.fantasypros.com/accounts/login/?next=http://www.fantasypros.com/index.php", login_data)

positions = ['qb','rb','wr','te','k']
for pos in positions:
	file = open('data/'+pos+'.xls','w')
	out = s.get("https://www.fantasypros.com/nfl/projections/"+pos+".php?export=xls&week=draft&min-yes=true&max-yes=true")
	file.write(out.text)

defi = open('data/de.xls','w')
defo = s.get('http://www.fantasypros.com/nfl/rankings/dst-cheatsheets.php?export=xls')
defi.write(defo.text)

rankf = open('data/rank.xls','w')
ranko = s.get('http://www.fantasypros.com/nfl/rankings/consensus-cheatsheets.php?export=xls')
rankf.write(ranko.text)

adpf = open('data/adp.xls','w')
adpo = s.get('https://fantasyfootballcalculator.com/adp_csv.php?format=standard&teams=10')
adpf.write(adpo.text)
