from collections import defaultdict
def lis(arr):
	n = len(arr)
	dp=defaultdict(int)
	for i in range(len(arr)):
		if dp[arr[i]-1]==0 and dp[arr[i]]==0:
			dp[arr[i]]+=1
		if dp[arr[i]-1]:
			dp[arr[i]]=dp[arr[i]-1]+1
	mx=max(dp.items(),key=lambda s:s[1])[0]
	s=[]
	for i in range(n-1,-1,-1):
		if arr[i]==mx:
			s.append(i+1)
			mx-=1
	s=s[::-1]
	print(len(s))
	print(*s)

a=input()
lst=list(map(int,input().strip().split()))
lis(lst)