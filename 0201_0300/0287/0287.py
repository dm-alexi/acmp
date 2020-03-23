with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n, m = (int(x) for x in f.readline().split())
    s = f.readline().strip()
    l = set(s[i : i + m] for i in range(n - m + 1))
    q.write(str(len(l)))
