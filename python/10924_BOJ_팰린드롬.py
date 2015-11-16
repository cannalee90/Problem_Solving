n = input()
s = map(int, raw_input().split(' '))
m = input()
for i in xrange(m):
	l, r = map(int, raw_input().split(' '))
	pal = s[l-1:r]
	if pal == pal[::-1]:
		print "1"
	else:
		print "0"

