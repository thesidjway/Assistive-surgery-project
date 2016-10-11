import re

f=open('test.xml')
g=open('test.new','w')
data=f.read()
tools=data.split('<PositionIndex>')
tools.pop(0)
i=1175
while i<len(tools)+1175:
	g.write(tools[i-1175][:5]+'\n')
	m1=tools[i-1175].find('<tool>')
	m2=tools[i-1175].find('</frame>')
	temp1=tools[i-1175][m1:m2]
	temp2=temp1.replace('<tool>','')
	temp3=temp2.replace('<tool>','')
	temp4=temp3.replace('</tool>','')
	temp5=temp4.replace('</tool>','')
	g.write(temp5)
	g.write("\n")
	i=i+1

