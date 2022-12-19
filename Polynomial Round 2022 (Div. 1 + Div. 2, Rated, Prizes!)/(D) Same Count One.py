t = int(input())
for _ in range(t):
	n,m = map(int,input().split())
	a = []
	d = {}
	ts = 0
	for i in range(n):
		a.append(list(map(int,input().split())))
		d[i] = sum(a[i])
		ts += d[i]
	if ts%n != 0:
		print(-1)
		continue
	am = ts//n
	ans = []
	for i in range(m):
		mx = []
		mn = []
		for j in range(n):
			if d[j] > am and a[j][i]==1:
				mx.append(j)
			elif d[j] < am and a[j][i]==0:
				mn.append(j)
		for k in range(min(len(mx),len(mn))):
			ans.append((mx[k]+1,mn[k]+1,i+1))
			d[mx[k]] -= 1
			d[mn[k]] += 1
	print(len(ans))
	for i in ans:
		print(*i)
