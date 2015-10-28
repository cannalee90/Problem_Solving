import sys
n = int(sys.stdin.readline())
m = int(sys.stdin.readline())
floyd = [[987654321 for col in xrange(n)] for row in xrange(n)]

for i in xrange(n):
    floyd[i][i] = 0

for i in xrange(m):
    u, v, w = map(int, sys.stdin.readline().split(' '))
    floyd[u - 1][v - 1] = min(floyd[u-1][v-1], w)

for k in xrange(n):
    for i in xrange(n):
        for j in xrange(n):
            floyd[i][j] = min(floyd[i][j], floyd[i][k] + floyd[k][j])

for i in xrange(n):
    for j in xrange(n):
        print floyd[i][j],
    print
