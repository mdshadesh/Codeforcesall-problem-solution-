n,k = map(int,input().split())
word = input()
a = 97
while k>0:
    temp = word.count(chr(a))
    if temp>0:
        
        
        if temp>k:
            word = word.replace(chr(a),'',k)
        else:
            word = word.replace(chr(a),'',temp)
        k -= temp
    a += 1
print(word)