from math import *

mod=1000000007
inf=10000000000000000

for _ in range(int(input())):
    a,b=input().split()
    c=''
    d=''
    for i in range(len(a)):
        c+=a[len(a)-1-i]
    for i in range(len(b)):
        d+=b[len(b)-1-i]
    l=int(c)+int(d)
    l=str(l)
    e=''
    for i in range(len(l)):
        e+=l[len(l)-1-i]
    print(int(e))
