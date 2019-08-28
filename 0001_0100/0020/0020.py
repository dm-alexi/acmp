def getLine(f):
    t = f.read(8192)
    k = f.read(1)
    while k != "" and k in "0123456789":
        t += k
        k = f.read(1)
    return t

with open("input.txt", "r") as f, open("output.txt", "w") as q:
    f.readline()   
    m = c = 1
    lres = 0
    t = getLine(f)
    s = (int(x) for x in t.split())
    last = next(s)
    while t:
        for cur in s:
            res = 1 if cur > last else -1 if cur < last else 0
            if res == lres or res == 0:
                if c > m:
                    m = c
                c = 0 if res == 0 else 1
            c += 1
            lres, last = res, cur
        t = getLine(f)
        s = (int(x) for x in t.split())
    if c > m:
        m = c
    q.write(str(m))
