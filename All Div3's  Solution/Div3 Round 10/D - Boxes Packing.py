n,m,k=map(int,input().split())
a=list(map(int,input().split()))
n=n-1
count=0
while(m>0 and n>=0):
    ktemp=k
    while(ktemp>=a[n] and n>=0):
        ktemp=ktemp-a[n]
        n=n-1
        count=count+1
    m=m-1
print(count)
		   		 	   	  		    		 	  	  	