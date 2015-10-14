stack = []
n = input()
for i in xrange(n):
    a=raw_input().split()
    q=a[0]
    if q == "push":
        y=int(a[1])
        stack.append(y)
    elif q == "size":
        print(len(stack))
    elif q == "pop":
        if len(stack) != 0:
            print(stack[-1])
            stack.pop()
        else:
            print("-1")
    elif q == "empty":
        if len(stack) == 0:
            print("1")
        else:
            print("0")
    else:
        if len(stack) == 0:
            print("-1")
        else:
            print(stack[-1])
