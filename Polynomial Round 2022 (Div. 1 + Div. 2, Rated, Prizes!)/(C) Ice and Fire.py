tests=int(input())
for i in range(tests):
    n=int(input())
    string=input()
    last_char='#'
    char_count=1
    for j in range(n-1):
        possible=j+1
        if last_char!=string[j]:
            last_char=string[j]
            char_count=1 
            print(possible,end=" ")
        else:
            print(possible-char_count,end=" ")
            char_count+=1 
    print()

