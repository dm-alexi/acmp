with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n, k = map(int, f.read().split())
    nf, kf = 1, 1
    for i in range(1, k + 1):
        kf *= i
        nf *= n - i + 1
    q.write(str(nf * nf // kf))
