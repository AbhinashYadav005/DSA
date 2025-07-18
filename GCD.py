def GCD(a,b):
    if b == 0:
        return a
    else:
        return GCD(b,a%b)
    
a,b= int(input('Enter a:')),int(input('Enter b:'))
print(f'The GCD is {GCD(a,b)}')