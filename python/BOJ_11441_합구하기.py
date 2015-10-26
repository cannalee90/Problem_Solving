import sys
n = int(sys.stdin.readline())
data = map(int, sys.stdin.readline().split(' '))
psum = [0 for _ in xrange(n + 1)]
for i in range(1, n + 1):
    psum[i] = data[i- 1] + psum[i-1]
m = int(sys.stdin.readline())
for i in xrange(m):
    a, b = map(int, sys.stdin.readline().split(' '))
    print(psum[b] - psum[a-1])
