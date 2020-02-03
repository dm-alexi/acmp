from collections import deque
def add(que, m, x, y, val):
    que.append((x, y))
    m[x][y] = val + 1

def board(p):
    m = [[-1 for j in range(8)] for i in range(8)]
    m[p[0]][p[1]] = 0
    que = deque()
    que.append(p)
    while que:
        x, y = que.popleft()
        if x < 7 and y < 6 and m[x + 1][y + 2] < 0:
            add(que, m, x + 1, y + 2, m[x][y])
        if x < 6 and y < 7 and m[x + 2][y + 1] < 0:
            add(que, m, x + 2, y + 1, m[x][y])
        if x < 6 and y > 0 and m[x + 2][y - 1] < 0:
            add(que, m, x + 2, y - 1, m[x][y])
        if x < 7 and y > 1 and m[x + 1][y - 2] < 0:
            add(que, m, x + 1, y - 2, m[x][y])
        if x > 0 and y > 1 and m[x - 1][y - 2] < 0:
            add(que, m, x - 1, y - 2, m[x][y])
        if x > 1 and y > 0 and m[x - 2][y - 1] < 0:
            add(que, m, x - 2, y - 1, m[x][y])
        if x > 1 and y < 7 and m[x - 2][y + 1] < 0:
            add(que, m, x - 2, y + 1, m[x][y])
        if x > 0 and y < 6 and m[x - 1][y + 2] < 0:
            add(que, m, x - 1, y + 2, m[x][y])
    return(m)

with open("input.txt", "r") as f, open("output.txt", "w") as q:
    pa, pb = ((ord(x[0]) - ord('a'), int(x[1]) - 1) for x in f.read().split())
    a, b = board(pa), board(pb)
    q.write("-1" if a[pb[0]][pb[1]] % 2 else str(min(a[i][j] for j in range(8) for i in range(8) if a[i][j] == b[i][j])))
