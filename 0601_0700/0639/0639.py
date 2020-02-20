with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n = int(f.readline())
    s = []
    for i in range(n):
        m = int(f.readline())
        for j in range(m):
            t = f.readline().split()
            s.append((float(t[0]), t[1]))
    s.sort(reverse = True)
    q.write(str(len(s)) + '\n' + '\n'.join("{:.2f} {}".format(x[0], x[1]) for x in s))
