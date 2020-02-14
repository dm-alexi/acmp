from collections import Counter
with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n, m = (int(x) for x in f.readline().split())
    alpha = {x : 0.0 for x in "abcdefghijklmnopqrstuvwxyz"}
    r = [None for i in range(n)]
    for i in range(n):
        r[i], d = f.readline().split()
        alpha[r[i]] = float(d)
    s = f.readline().strip()
    l = len(s)
    counter = Counter(s)
    mes = {x : counter[x] / l for x in "abcdefghijklmnopqrstuvwxyz"}
    alpha = [x[0] for x in sorted(alpha.items(), key = lambda kv : kv[1])]
    mes = [x[0] for x in sorted(mes.items(), key = lambda kv : kv[1])]
    q.write("\n".join(mes[alpha.index(x)] for x in r))
