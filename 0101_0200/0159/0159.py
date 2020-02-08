with open("input.txt", "r") as f, open("output.txt", "w") as q:
    p = [None] * int(f.readline())
    k = 1
    for i in f.read().split():
        p[int(i) - 1] = k
        k += 1
    q.write(" ".join(str(x) for x in p))
