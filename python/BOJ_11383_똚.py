n, m = map(int, raw_input().split(' '))
data = []
for i in xrange(n):
	data.append(raw_input())
isEyfa = True
	
for i in xrange(n):
	tmp = raw_input()
	for j in xrange(m):
		if data[i][j] != tmp[j * 2] or data[i][j] != tmp[j * 2 + 1]:
			isEyfa = False
print isEyfa == True and "Eyfa" or "Not Eyfa"
