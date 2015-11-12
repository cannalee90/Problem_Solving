n, m, l = map(int, raw_input().split(' '))
cnt = [0] * n
idx = 0
ans = 0
while True:
	cnt[idx] += 1
	if cnt[idx] >= m: 
		break;
	ans += 1
	if cnt[idx] % 2 == 1: 
		idx += l
		idx = idx % n
	else:
		idx -= l
		idx = idx < 0 and idx + n or idx
print ans