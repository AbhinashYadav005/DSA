import time
def TOH(n,src,dst,tmp):
    if n == 1:
        print(f'Move {n} disc from {src} to {dst}')
    else:
        TOH(n-1,src,tmp,dst)
        print(f'Move {n} disc from {src} to {dst}')
        TOH(n-1,dst,tmp,src)
        
n = int(input('Enter n: '))

start = time.time()
TOH(n,'A','C','B')
end = time.time()

print(f'Execution time: {end-start} seconds')