dic = {}
for z in range(int(input())):
	n = int(input())
	arr = list(map(int,input().split()))
	sm = sum(arr)
	for i in range(n):
		new = sm-arr[i]
		if new in dic and dic[new][0] != z:
			print('YES')
			print(dic[new][0]+1, dic[new][1]+1)
			print(z+1,i+1)
			raise SystemExit(0)
		elif new not in dic:
			dic[new] = (z,i)
print('NO')

