with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n = int(f.readline())
    s = [[0 for j in range(100)] for i in range(100)]
    for c in range(n):
        x1, y1, x2, y2 = (int(x) for x in f.readline().split())
        for i in range(min(y1, y2), max(y1, y2)):
            for j in range(min(x1, x2), max(x1, x2)):
                s[i][j] += 1
    x1, y1, x2, y2 = (int(x) for x in f.readline().split())
    q.write(str(sum(s[i][j] for j in range(min(x1, x2), max(x1, x2)) for i in range(min(y1, y2), max(y1, y2)))))
