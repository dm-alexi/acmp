with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n = int(f.readline())
    p = [int(x) for x in f.read().split()]
    p.extend((0, 1000000000))
    p.sort()
    i, k, s = 0, 0, 0
    while i < 2 * n + 1:
        j = i + 1
        s = p[i + 1] - p[i]
        while j < 2 * n and p[j + 1] == p[j]:
            s += p[j + 2] - p [j + 1]
            j += 2
        if s > k:
            k = s
        i = j + 1
    q.write(str(k))
