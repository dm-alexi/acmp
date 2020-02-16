with open("input.txt", "r") as f, open("output.txt", "w") as q:
    f.readline()
    p = list(set(int(x) for x in f.read().split()))
    p.sort()
    k = len(p)
    l = []
    l.append(str(p[0]))
    j = 0
    for i in range(1, k):
        if i < j:
            continue
        j = i
        while j < k and p[j] == p[j - 1] + 1:
            j += 1
        if j - i < 2 or (j - i == 2 and p[i] > -100 and p[i] < 1000):
            l.append(str(p[i]))
            j = i
        else:
            l.append("...")
            l.append(str(p[j - 1]))
    q.write(", ".join(l))
