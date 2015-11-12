import sys
n = int(sys.stdin.readline())
side = []
for i in xrange(n):
    side.append(int(sys.stdin.readline()))
ans = -1
side.sort()
for i in xrange(n - 1, 1, -1):
    if side[i] < side[i-1] + side[i -2]:
        ans = max(ans, side[i] + side[i-1] + side[i-2])
print ans