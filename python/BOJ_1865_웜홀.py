import sys
tc = input()
while tc:
    tc -= 1
    n, m, q = map(int, sys.stdin.readline().split(' '))
    graph= [[] for i in xrange(n + 1)]
    for i in xrange(m):
        u, v, w = map(int, sys.stdin.readline().split(' '))
        graph[u].append((v, w))
        graph[v].append((u, w))
    for i in xrange(q):
        u, v, w = map(int, sys.stdin.readline().split(' '))
        graph[u].append((v, -w))
    def bell():
        global graph
        dis = [987654321] * (n + 1)
        dis[1] = 0
        for i in xrange(n):
            update = False
            for j in xrange(1, n + 1):
                for k in graph[j]:
                    next = k[0]
                    cost = k[1]
                    if dis[next] > dis[j] + cost:
                        dis[next] = dis[j] + cost
                        update = True
            if update is False:
                return False
        return True
    if bell() is True:
        print "YES"
    else:
        print "NO"