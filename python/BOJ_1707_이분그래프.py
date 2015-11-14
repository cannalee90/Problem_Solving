import sys
sys.setrecursionlimit(200001)

t = input()
while t:
	t -= 1
	n, m = map(int, raw_input().split(' '))
	bi = [[] for i in xrange(n + 1)]
	check = [0] * (n + 1)

	for i in xrange(m):
		u, v = map(int, raw_input().rstrip().split(' '))
		bi[u].append(v)
		bi[v].append(u)	

	isBi = True

	def dfs(here, status):
		global bi, isBi, check
		check[here] = status
		status = (status == 1 and  2 or 1)
		for next in bi[here]:
			if check[next] == 0:
				dfs(next, status)
			if check[here] == check[next]:
				isBi = False;

	for i in xrange(1, n+1):
		if check[i] == 0:
			dfs(i, 1)

	print isBi == True and "YES" or "NO"


