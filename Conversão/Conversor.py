#Conversor Binario

def conversor(numero, nbits = 10):
    if(numero < 1 and numero > 0 and nbits >=  1 and nbits<= 30):
        menor = c(numero,nbits)
        if(numero != menor[1]):
            print('Menor')
            print('Binario: 0,' + menor[0])
            print('Decimal Obtido: '+ str(menor[1]))
            print('Erro: ' + str(round(((numero - menor[1])/numero)*100, 4)) +'%')
            maior = c(numero+(1/(2**nbits)), nbits)
            print('Maior')
            print('Binario: 0,' + maior[0])
            print('Decimal Obtido: ' + str(maior[1]))  
            print('Erro: ' + str(round(((-1*(numero - maior[1]))/numero)*100, 4)) +'%')
        else:
            print('Valor possui representação exata em binario')
            print('Binario: 0,' + menor[0])
            print('Decimal: '+ str(menor[1]))
    else:
        print('Parametros passados não são validos')

def c(numero, nbits = 10):
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
    
