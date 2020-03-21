with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n = int(f.readline())
    p = [int(x) for x in f.readline().split()]
    f.readline()
    s = f.readline().split()
    d = [s.count(str(i)) for i in range(1, n + 1)]
    q.write("\n".join("yes" if d[i] > p[i] else "no" for i in range(n)))
