def checkstr(s):
    if len(s) % 2:
        return False
    d = {')' : '(', ']' : '[', '}' : '{'}
    t = []
    for x in s:
        if t and x in d and d[x] == t[-1]:
            t.pop()
        elif t and x in d and t[-1] in d.values() and d[x] != t[-1]:
            return False
        else:
            t.append(x)
    for i in range(len(t) // 2):
        if d[t[i]] != t[-i - 1]:
            return False
    return True

with open("input.txt", "r") as f, open("output.txt", "w") as q:
    q.write("YES" if checkstr(f.readline().strip()) else "NO")
