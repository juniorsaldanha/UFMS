#!/usr/bin/python
MONGES = 0
CANIBAIS = 1
BARCO = 2

def valido(state):
	ret = True
	cstate = [3-state[MONGES], 3-state[CANIBAIS]]
	
	if state[MONGES] < 0 or state[CANIBAIS] < 0:
		ret = False
	
	if state[MONGES] > 3 or state[CANIBAIS] > 3:
		ret = False
	
	if cstate[MONGES] < 0 or cstate[CANIBAIS] < 0:
		ret = False
	
	if cstate[MONGES] > 3 or cstate[CANIBAIS] > 3:
		ret = False
	
	if state[MONGES] != 0 and state[MONGES] < state[CANIBAIS]:
		ret = False

	if cstate[MONGES] != 0 and cstate[MONGES] < cstate[CANIBAIS]:
		ret = False

	return ret

def gera_filhos(state):
	ret = []
	binvert = state[BARCO]*-1

	#	2 monges
	aux = state[:]
	aux[MONGES] = aux[MONGES] + 2*binvert
	aux[BARCO] = binvert
	if valido(aux):
		ret.append(aux)

	#	2 canibais
	aux = state[:]
	aux[CANIBAIS] = aux[CANIBAIS] + 2*binvert
	aux[BARCO] = binvert
	if valido(aux):
		ret.append(aux)

	#	1 monge 1 canibal
	aux = state[:]
	aux[MONGES] = aux[MONGES] + binvert
	aux[CANIBAIS] = aux[CANIBAIS] + binvert
	aux[BARCO] = binvert
	if valido(aux):
		ret.append(aux)

	#	1 monge
	aux = state[:]
	aux[MONGES] = aux[MONGES] + binvert
	aux[BARCO] = binvert
	if valido(aux):
		ret.append(aux)

	#	1 canibal
	aux = state[:]
	aux[CANIBAIS] = aux[CANIBAIS] + binvert
	aux[BARCO] = binvert
	if valido(aux):
		ret.append(aux)

	return ret

if __name__ == '__main__':
	start = [3,3,1]
	for filhos in gera_filhos(start):
		print(filhos)

def estado2str(s):
    return "%d %d %d"%(s[0],s[1],s[2])


if __name__ == '__main__':
    start = [3,3,1]
    filhos = gera_filhos(start)
    print filhos
    stop  = [0,0,-1]
    lista = [start]
    visitou = []
    dpai = dict()
    pai = start
    while(len(lista)>0 and pai != stop):
       
        if pai not in visitou:
            visitou.append(pai)
            filhos = gera_filhos(pai)
            lista = filhos + lista
            tfilhos = []
            print pai,filhos
            for filho in filhos:
                    sfilho =  estado2str(filho)
                    if sfilho not in dpai:
                        dpai[sfilho]=estado2str(pai)
                    print '--->', filho,pai
        pai = lista[0]
        del lista[0]
 
    spai = estado2str(stop)
    cont = 0
    while spai != '3 3 1' and cont < 20 :
       print spai
       spai = dpai[spai]
       cont += 1
    print spai