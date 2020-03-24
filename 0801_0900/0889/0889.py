with open("input.txt", "r") as f, open("output.txt", "w") as q:
    k, m = (int(x) for x in f.readline().split())
    s = sorted([[int(x) for x in f.readline().split()] for i in range(m)], key = lambda x: x[1], reverse = True)
    for t in s:
        k = k - 1 if k == t[0] + 1 else k + 1 if k == t[0] else k
    q.write(str(k))
