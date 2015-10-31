n = input()
graph = []
visited = [[False]*n for i in xrange(n)]
for i in xrange(n):
    graph.append(map(int, raw_input().split(' ')))
flag = False
for k in xrange(n):
    for i in xrange(n):
        for j in xrange(n):
            if k == i or k == j: continue
            if graph[i][j] > graph[i][k] + graph[k][j]: flag = True
            if graph[i][j] == graph[i][k] + graph[k][j]: visited[i][j] = True
ans = 0
if flag == True: print("-1")
else:
    for i in xrange(n):
        for j in xrange(n):
            if visited[i][j] == False: ans = ans + graph[i][j]
    print(ans / 2)