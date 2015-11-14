t = int(raw_input())
while t:
    t -= 1
    n = int(raw_input())
    goal = -1
    ans = ""
    for i in xrange(n):
        a, b = raw_input().split(' ')
        if(int(a) > goal):
            goal = int(a)
            ans = b
    print ans