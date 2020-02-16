with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n = int(f.readline())
    p = [int(x) for x in f.read().split()]
    p.sort()
    k = sum(p[i] // 2 + 1 for i in range(n // 2 + 1))
    q.write(str(k))
