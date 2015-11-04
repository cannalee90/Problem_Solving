n = str(raw_input())
ciper = "PER"
ans = 0
for c in xrange(len(n)):
    if n[c] != ciper[c % 3]:
        ans += 1
print ans
