MAX = 100
table = [0] * MAX

def Fibo(n):
    if(n == 1 or n==2):
        return 1
    else:
        if table[n] == 0:
            table[n]= Fibo(n-1) + Fibo(n-2)
        return table[n]
    
n = int(input('Enter n: '))
print(f'The fibonacci is {Fibo(n)}')