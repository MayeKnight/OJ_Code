for k in range(1, 10):
    lst = [0] * 8
    for i in range(1, 10000000):
        s = str(i)
        length = len(s)
        if i % k == 0 and s == s[::-1]:
            lst[length] = max(lst[length], i)
    print(k, ": ", lst)
