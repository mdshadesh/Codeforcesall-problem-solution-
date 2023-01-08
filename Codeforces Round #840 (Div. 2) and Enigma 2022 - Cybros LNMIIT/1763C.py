T = int(input())
while T:
	T -= 1
	n = int(input())
	a = [ int (i) for i in input (). split ()]
	if n > 3 :
		print( n * max(a))
	elif n == 2 :
		print( max(sum(a), n * abs(a[0] - a[1])))
	elif n == 3 :
		print( max(sum(a), n * a[0], n * a[2], n * abs(a[0] - a[2]), n * abs(a[0]-a[1]), n * abs(a[1]-a[2])))

