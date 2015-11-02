n , m = map(int, raw_input().split(' '))
parent = [[-1] * n for i in xrange(n)]

floyd = [[987654321] * n for i in xrange(n)]
for i in xrange(n):
    floyd[i][i] = 0
for i in xrange(m):
    u, v, w = map(int, raw_input().split(' '))
    floyd[u - 1][v - 1] = w
    floyd[v - 1][u - 1] = w
    parent[u-1][v-1] = v - 1  #Edge u -> v 일때 v를 기록한다.그리고 floyd에서 경로를 사용하게 되면 parent[i][j] = paren[i][k] 라는 방식으로 값을 갱신시켜주면
    parent[v-1][u-1] = u - 1  #답이 나오게 된다.

for k in xrange(n):
    for i in xrange(n):
        for j in xrange(n):
            if floyd[i][j] > floyd[i][k] + floyd[k][j]:
                floyd[i][j] = floyd[i][k] + floyd[k][j]
                parent[i][j] = parent[i][k]

for i in xrange(n):
    for j in xrange(n):
        if parent[i][j] == -1:
            print '-',
        else:
            print parent[i][j] + 1,
    print
