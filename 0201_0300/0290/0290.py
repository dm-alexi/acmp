with open("input.txt", "r") as f, open("output.txt", "w") as q:
    nb, mb = (int(x) for x in f.readline().split())
    base = [f.readline().strip() for i in range(nb)]
    n, m = (int(x) for x in f.readline().split())
    p = 0
    t = [f.readline().strip() for i in range(n)]
    for i in range(n - nb + 1):
        for j in range(m - mb + 1):
            r = 1
            k = 0
            while r and k < nb:
                for l in range(mb):
                    if base[k][l] == '#' and t[i + k][j + l] == '.':
                        r = 0
                        break
                k += 1
            p += r
    q.write(str(p))
