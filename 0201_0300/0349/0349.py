with open("input.txt", "r") as f, open("output.txt", "w") as q:
    m, n = map(int, f.readline().split())
    s = "Absent"
    p = [True] * (n + 1)
    i = 3
    while i * i <= n:
        if p[i]:
            for j in range(i * i, n + 1, 2 * i):
                p[j] = False
        i += 2
    if m == 2:
        q.write("2\n")
        s = ""
    t = [str(k) for k in filter(lambda x: p[x], range(m if m % 2 else m + 1, n + 1, 2))]
    q.write('\n'.join(t) if t else s)
