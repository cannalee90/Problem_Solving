n = input()
cute = 0
noncute = 0
for i in xrange(n):
    if input() == 0:
        noncute += 1
    else:
        cute += 1
if cute > noncute:
    print "Junhee is cute!"
else:
    print "Junhee is not cute!"
