len_ar = int(input())
ar = list(map(int,input().split(" ")))

n_ar = []

for b in range(len_ar-1,-1,-1):
    if(ar[b] not in n_ar):
        n_ar.append(ar[b])

print(len(n_ar))

for h in range(len(n_ar)-1,-1,-1):
    print(n_ar[h], end=' ')

print('\n')

		 	 	 	 	  	  	  		   	 		