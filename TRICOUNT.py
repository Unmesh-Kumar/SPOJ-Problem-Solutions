def sq(n):
    return (n*(n+1)*(2*n+1))//6
def sm(n):
    return (n*(n+1))//2

for _ in range(int(input())):
    n=int(input())
    if n%2==1:
        z=sq(n)-4*sq(n//2)-sm(n)+2*sm(n//2)
    else:
        z=4*sq(n//2)-2*sm(n//2)
    x=(n*(n+1)*(n+2))//6+z//2
    print(x)
