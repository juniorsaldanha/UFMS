#!/usr/bin/python

def minhafuncao(a):
	print(a+1000)
	a += 50

if __name__ == '__main__':
	s = 'Evandro Goes Saldanha Junior'
	print("Tamanho do nome %d"%(len(s.split())))
	v = s.split()
	for nome in v:
		print(nome)
	for i in range(10,20,2):
		minhafuncao(i)
		print(i)
	print("	\nNome: %s"%(s))