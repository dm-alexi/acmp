with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n = int(f.readline())
    p = [int(x) for x in f.readline().split()]
    s = 0 if n == 1 else abs(p[1] - p[0])
    prev = 0
    for i in range(2, n):
        t = s
        s = min(s + abs(p[i] - p[i - 1]), prev + 3 * abs(p[i] - p[i - 2]))
        prev = t
    q.write(str(s))
