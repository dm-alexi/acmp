with open("input.txt", "r") as f, open("output.txt", "w") as q:
    s = f.read()
    n = len(s)
    i, k = 0, 0
    while i < n:
        if s[i] == "'":
            i = s.index("'", i + 1)
        elif s[i : i + 2] == '//':
            k += 1
            i = s.index('\n', i + 2) if '\n' in s[i + 2 : ] else n - 1
        elif s[i : i + 2] == '(*':
            k += 1
            i = s.index('*)', i + 2)
        elif s[i] == '{':
            k += 1
            i = s.index('}', i + 1)
        i += 1
    q.write(str(k))
