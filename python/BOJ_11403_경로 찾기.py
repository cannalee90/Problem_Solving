n = input()
floyd = []
for i in xrange(n):
    floyd.append(map(int, raw_input().split((' '))))
for k in xrange(n):
    for i in xrange(n):
        for j in xrange(n):
            if floyd[i][k] is 1 and floyd[k][j] is 1:  floyd[i][j] = 1
for i in xrange(n):
    for j in xrange(n):
        print floyd[i][j],
    print
