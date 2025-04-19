import math
n,m=map(int,raw_input().split())
delta = (n+1-m)**2-4*n
rad = int(math.sqrt(delta))
p = (n+1-m-rad)/2
q = (n+1-m+rad)/2
print p,' ',q