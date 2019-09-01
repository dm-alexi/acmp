with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n, m = (int(x) for x in f.readline().split())
    p = [0] * n
    for i in (int(x) for x in f.read().split()):
        p[i - 1] += 1
    q.write(" ".join(str(x) for x in p))
