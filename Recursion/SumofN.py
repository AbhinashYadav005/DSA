def SUM(n):
    if n==1:
        return 1
    else:
        return n+SUM(n-1)

n = int(input('Enter n: '))
print(f'The sum of {n}th natural numbers is {SUM(n)}')