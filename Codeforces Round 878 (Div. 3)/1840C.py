tests=int(input())
while(tests>0):
    tests-=1
    n, k, q = map(int, input().split())
    array = list(map(int, input().split()))
    answer = 0;count = 0
    for i in range(n):
        if array[i] <= q:
            count += 1
        else:
            count = 0
        if count >= k:
            answer += count - k + 1
    print(answer) 

			  	    	 	  	 	  	  					