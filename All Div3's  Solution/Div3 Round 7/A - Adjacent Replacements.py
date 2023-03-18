input()
print(*(i+i%2-1for i in map(int,input().split())))