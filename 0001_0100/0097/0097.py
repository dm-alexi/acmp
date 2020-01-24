from collections import Counter

def getline(f):
    x1, y1, x2, y2, r = (int(x) for x in f.readline().split())
    return [min(x1, x2) - r, min(y1, y2) - r, max(x1, x2) + r, max(y1, y2) + r]

def intersect(a, b):
    return not (a[0] > b[2] or a[2] < b[0] or a[1] > b[3] or a[3] < b[1])

with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n = int(f.readline())
    s = [getline(f) for i in range(n)]
    m = [[i, {i}] for i in range(n)]
    for i in range(n):
        for j in range(i + 1, n):
            if intersect(s[j], s[i]):
                for x in m[m[j][0]][1]:
                    m[m[i][0]][1].add(x)
                    m[x][0] = m[i][0]
                m[j][1].clear()
    q.write(str(len(Counter((a[0] for a in m)).keys())))
