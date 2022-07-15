n=int(input())
def fact(n):
    if n==0 or n==1:
        return 1
    else:
        m=n*fact(n-1)
        return m

print(fact(n))