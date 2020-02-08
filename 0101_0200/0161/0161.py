with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n = int(f.readline())
    p = [int(x) for x in f.read().split()]
    d = [i + 1 for i in range(n)]
    for i in range(n - 1, 0, -1):
        if p[i]:
            d.insert(i, d.pop(i - p[i]))
    q.write(" ".join(str(x) for x in d))
