t = int(input())
for _ in range(t):
    n = int(input())
    res = ""
    s = input()
    i=0
    while i<len(s):
        j = i+1
        res = res+s[i]
        while(s[i]!=s[j]):
            j = j+1
        i = j+1
    print(res)
			 		  					 	  		 						 				