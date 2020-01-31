with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n, m = (int(x) for x in f.readline().split())
    d = [30000 for i in range(n)]
    d[0] = 0
    edges = []
    for i in range(m):
        a, b, r = (int(x) for x in f.readline().split())
        edges.append((a - 1, b - 1, r))
    for i in range(n - 1):
        stop = True
        for edge in edges:
            if d[edge[0]] < 30000 and d[edge[1]] > d[edge[0]] + edge[2]:
                stop = False
                d[edge[1]] = d[edge[0]] + edge[2]
        if stop:
            break
    q.write(' '.join(str(x) for x in d))
