def timeint(s):
    return int(s[:2]) * 60 + int(s[3:])

with open("input.txt", "r") as f, open("output.txt", "w") as q:
    m = 0
    inlist, outlist = [], []
    n = int(f.readline())
    for i in range(n):
        a, b = (timeint(x) for x in f.readline().split())
        inlist.append(a)
        outlist.append(b)
    inlist.sort()
    outlist.sort()
    i, j, c = 0, 0, 0
    while i < n:
        if inlist[i] <= outlist[j]:
            i += 1
            c += 1
            if c > m:
                m = c
        else:
            j += 1
            c -= 1
    q.write(str(m))
