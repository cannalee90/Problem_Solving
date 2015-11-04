n = input()
data = map(int, raw_input().split(' '))
begin = 0
ans = -987654321
for i in xrange(1, n):
    if data[i] <= data[i-1]:
        ans = max(ans, data[i - 1] - data[begin])
        begin = i
print max(ans, data[n-1] - data[begin])


