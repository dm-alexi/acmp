with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n = int(f.readline())
    d = {'m':1, 'g':1000, 'k':1000000, 'M':1000000000, 't':1000000000, 'G':1000000000000, 'p':16380000}
    m = []
    for i in range(n):
        k = f.readline()
        s = k.split()
        num = int(s[0]) * d[s[1][0]]
        if len(s[1]) > 1:
            num *= (d[s[1][1]] // 1000)
        m.append((num, i, k))
    m.sort()
    q.write("".join(x[2] for x in m))
