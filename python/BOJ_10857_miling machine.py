n, m = map(int, raw_input().split(' '))
w, h = map(int, raw_input().split(' '))
slide = []
machine = [-1] * w
for i in xrange(n):
    slide.append(map(int, raw_input().split(' ')))
for i in xrange(m):
    tmp = map(int, raw_input().split(' '))
    for j in range(w):
        machine[j] = max(machine[j], tmp[j])

for i in xrange(n):
    for j in xrange(w):
        print min(h - int(machine[j]), slide[i][j]) ,
    print
