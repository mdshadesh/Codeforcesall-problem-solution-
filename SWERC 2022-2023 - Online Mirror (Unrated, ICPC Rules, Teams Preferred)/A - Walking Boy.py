from math import floor
t = int(input())
for i in range(t):
    x = int(input())
    arr = list(map(int, input().split())) 
    arr.insert(0,0)
    arr.append(1440)
    count = 0
    for i in range(len(arr)-1):
        diff = arr[i+1] - arr[i]
        if diff >=120:
            count+= floor(int(diff/120))
    if count>=2:
        print("YES")
    else:
        print("NO")
		 	   		 			    		  	  		   	