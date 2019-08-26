with open("input.txt", "r") as f, open("output.txt", "w") as q:
    s = "2"
    p = [True] * (20222)
    i = 3
    while i <= 20222:
        if p[i]:
            for j in range(i * i, 20222, 2 * i):
                p[j] = False
        i += 2
    for i in range(3, 20222, 2):
        if p[i]:
            s += str(i)
    t = [int(x) for x in f.read().split()[1:]]
    d = ""
    for i in t:
        d += s[i - 1]
    q.write(d)
    
    
