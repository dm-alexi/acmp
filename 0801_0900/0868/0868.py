with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n, m = (int(x) for x in f.readline().split())
    p = [[int(x) for x in f.readline().split()] for i in range(n)]
    col = 0
    for i in range(1, n):
        if max(p[i]) > max(p[col]):
            col = i
    row = p[col].index(max(p[col]))
    p.sort(key = lambda x : x[row], reverse = True)
    q.write(str(p[n - 1][p[0].index(min(p[0]))]))
