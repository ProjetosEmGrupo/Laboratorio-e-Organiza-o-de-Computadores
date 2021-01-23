#Conversor IEEE 754

def n(n,nbits = 32):
    if(n > 0):
        sinal = '0'
        normal = n
    else:
        sinal = '1'
        normal = n * -1
    bi = bina(int(normal))
    bd = conversor(normal - int(normal), nbits)
    if(int(normal) == 0):
        i = 0        
        while bd[0] != '1':
            bd = bd[1:]
            i = i - 1
        i = i - 1
        sinal = sinal 
        mantissa = bd[1:]
    else:
        i = len(bi) - 1
        mantissa = bi[1:] + bd
    expoente = 127 + i
    if(n == 0):
        r = nbits * '0'
    else:
        r = sinal + str(bina(expoente)) + mantissa
    print("Binario: ",end="")
    print(r[0:nbits])
    print("Hexadecimal: ",end="")
    for i in range(0,nbits,4):
        print(hexa(bhex(r[i:i+4])),end="")

def conversor(numero, nbits = 32):
    menor = c(numero,nbits)
    if(numero != menor[1]):
        maior = c(numero+(1/(2**nbits)), nbits)      
        if(round(((numero - menor[1])/numero)*100, 4) > round(((-1*(numero - maior[1]))/numero)*100, 4)):
            return str(maior[0])
    return str(menor[0])

def c(numero, nbits = 32):
    n = numero    
    smenor = ""
    fmenor = 0
    for i in range(1, nbits+1): 
        n = n * 2
        if n < 1:
            smenor = smenor + '0'
        else:
            smenor = smenor + '1'
            n = n - 1
            fmenor = fmenor + (1 / (2 **i))
    return [smenor, fmenor]
    
#converção binario
def bina(n):
    s = ""
    while n > 1:
        s = str(n % 2) + s
        n = n // 2;
    s = str(n) + s
    return s

def bhex(n):
    i = 0
    
    if(n[0] == '1'): i = i + 8
    if(n[1] == '1'): i = i + 4
    if(n[2] == '1'): i = i + 2
    if(n[3] == '1'): i = i + 1
    return i

#conversão hexadecimal
def hexa(n):
    s=""
    while n > 15:
        if(n%16 < 10):
            s = str(n % 16) + s
        elif(n%16 == 10):
            s = str('A') + s
        elif(n%16 == 11):
            s = str('B') + s
        elif(n%16 == 12):
            s = str('C') + s
        elif(n%16 == 13):
            s = str('D') + s
        elif(n%16 == 14):
            s = str('E') + s
        elif(n%16 == 15):
            s = str('F') + s
        n = n // 16
    if(n < 10):
        s = str(n) + s
    elif(n == 10):
        s = str('A') + s
    elif(n == 11):
        s = str('B') + s
    elif(n == 12):
        s = str('C') + s
    elif(n == 13):
        s = str('D') + s
    elif(n == 14):
        s = str('E') + s
    elif(n == 15):
        s = str('F') + s
    return s
