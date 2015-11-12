t = input()
while t:
	t -= 1
	n = input()
	ans = 0
	check = [False] * (n + 1)
	for i in xrange(2, n + 1):
		idx = i
		while idx <= n:
			check[idx] = check[idx] is False and True or False
			idx += i
	for i in xrange(1, n + 1):
		if check[i] is False: ans +=1
	print ans