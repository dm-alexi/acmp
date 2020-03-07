def number(t):
    if not '^' in t:
        return int(t)
    tmp = t.split('^')
    sign = -1 if t[0] == '-' else 1
    return sign * (abs(int(tmp[0])) ** int(tmp[1]))

def variable(t, x):
    sign = -1 if t[0] == '-' else 1
    if not '^' in t:
        return sign * x
    return sign * (x ** int(t.split('^')[1]))

import re
with open("input.txt", "r") as f, open("output.txt", "w") as q:
    s = [i for i in re.split(r"([+-][^+-]*)", f.readline().strip()) if i]
    x = int(f.readline())
    a = 0
    for t in s:
        if not 'x' in t:
            a += number(t)
        elif not '*' in t:
            a += variable(t, x)
        else:
            tmp = t.split('*')
            a += number(tmp[0]) * variable(tmp[1], x)
    q.write(str(a))
