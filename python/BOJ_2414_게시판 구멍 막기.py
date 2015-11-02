n, m = map(int, raw_input().split(' '))
graph = []
row = [[-1] * m for i in xrange(n)]
height = [[-1] * m for i in xrange(n)]
for i in xrange(n):
    graph.append(raw_input())
cnt = 0

for i in xrange(n):
    for j in xrange(m):
        if graph[i][j] == ".": continue
        if j != 0 and row[i][j - 1] != -1:
            row[i][j] = row[i][j-1]
        elif j == 0 or row[i][j -1] == -1:
            row[i][j] = cnt
            cnt += 1

vertex = [[] for i in xrange(cnt)]

cnt = 0
for j in xrange(m):
    for i in xrange(n):
        if graph[i][j] == '.': continue
        if i != 0 and height[i-1][j] != -1:
            height[i][j] = height[i-1][j]
        elif i == 0 or height[i - 1][j] == -1:
            height[i][j] = cnt
            cnt += 1

check = [False] * cnt
match = [-1] * cnt
for i in xrange(n):
    for j in xrange(m):
        if graph[i][j] == '.' : continue
        u = row[i][j]
        v = height[i][j]

        vertex[u].append(v)

def f(x):
    global match, vertex, check
    for v in vertex[x]:
        if not check[v]:
            check[v] = True
            if match[v] == -1 or f(match[v]):
                match[v] = x
                return True
    return False


ans = 0

for i in xrange(len(vertex)):
    for j in xrange(cnt):
        check[j] = False
    if f(i) is True:

        ans += 1
print(ans)
