with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n = int(f.readline()) - 1
    p = [int(x) for x in f.read().split()]
    s = [0, 0]
    i = k = 0
    while i < n:
        s[k % 2] += max(p[i], p[n])
        if p[i] < p[n]:
            n -= 1
        else:
            i += 1
        k += 1
    s[k % 2] += p[i]
    q.write("{}:{}".format(s[0], s[1]))
    
