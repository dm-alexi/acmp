with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n, k = f.read().split()
    s = [str(i) for i in range(1, int(n) + 1)]
    s.sort()
    q.write(str(s.index(k) + 1))
