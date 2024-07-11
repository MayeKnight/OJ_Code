for _ in range(int(input())):
    s = list(input())
    n = len(s)

    upper = []
    lower = []
    for i, v in enumerate(s):
        if v == "b":
            s[i] = ""
            if lower:
                s[lower.pop()] = ""
            continue

        if v == "B":
            s[i] = ""
            if upper:
                s[upper.pop()] = ""
            continue

        if "a" <= v <= "z":
            lower.append(i)
        else:
            upper.append(i)

    print(''.join(s))
