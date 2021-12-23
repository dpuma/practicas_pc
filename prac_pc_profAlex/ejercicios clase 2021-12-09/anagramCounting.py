import sys

factoriales = {0: 1} # caso base

for i in range(1, 105): # calcula limite max de factoriales 
    factoriales[i] = factoriales[i-1]*i

for entrada in sys.stdin:
    expresion = str(entrada.split()[0]) # recibe entrada 
    repetidas = {}
    
    for letra in expresion: # calcula repetidas
        if ord(letra) in repetidas:
            repetidas[ord(letra)] += 1
        else:
            repetidas[ord(letra)] = 1
            
    sol = factoriales[len(expresion)] # calcula numerador
    
    for i in repetidas:
        sol = sol // factoriales[repetidas[i]] # divide según repetidas
        
    print(sol)