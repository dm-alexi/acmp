with open("input.txt", "r") as f, open("output.txt", "w") as q:
    s = f.readline().strip()
    t = f.readline().strip()
    d = {t[i:] + t[:i] for i in range(len(t))}
    k = 0
    for x in d:
        n = s.find(x, 0)
        while n > -1:
            k += 1
            n = s.find(x, n + 1)
    q.write(str(k))

        
