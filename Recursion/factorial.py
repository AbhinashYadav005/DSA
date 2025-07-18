def TailFact(n,a):
    if n == 1:
        return a
    else:
        return TailFact(n-1,a*n)
    
n = int(input("Enter n: "))

print(f"The factorial is {TailFact(n,1)}")