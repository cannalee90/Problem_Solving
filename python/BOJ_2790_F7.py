n = int(raw_input())
data=[[] for i in xrange(n)]
for i in xrange(n):
    data[i] = int(raw_input())
data.sort()
mmax = -1
ans = 0
for i in xrange(n):
    mmax = max(mmax, data[i] + (n - i))
for i in data:
    if i + n >= mmax:
        ans = ans + 1
print(ans)