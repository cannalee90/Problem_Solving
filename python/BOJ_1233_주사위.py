n, m, p = map(int, raw_input().split(' '))
cnt = [0] * 100
ans = 0
ansp = -1
for i in xrange(1, n + 1):
    for j in xrange(1, m + 1):
        for k in xrange(1, p + 1):
            point = i + j + k
            cnt[point] += 1
            ans = ansp < cnt[point] and point or ans
            ansp = ansp < cnt[point] and cnt[point] or ansp
print ans

