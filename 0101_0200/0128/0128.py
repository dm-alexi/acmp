from collections import deque
def add(que, x, y, s, k):
    s[x][y] = k
    que.append((x, y))
    
with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n = int(f.readline())
    s = [[-1 for i in range(n)] for j in range(n)]
    a = [int(x) - 1 for x in f.read().split()]
    s[a[0]][a[1]] = 0
    que = deque()
    que.append(a[:2])
    while s[a[2]][a[3]] < 0:
        x, y = que.popleft()
        if x >= 2 and y >= 1 and s[x - 2][y - 1] < 0:
            add(que, x - 2, y - 1, s, s[x][y] + 1)
        if x >= 1 and y >= 2 and s[x - 1][y - 2] < 0:
            add(que, x - 1, y - 2, s, s[x][y] + 1)
        if x < n - 2 and y < n - 1 and s[x + 2][y + 1] < 0:
            add(que, x + 2, y + 1, s, s[x][y] + 1)
        if x < n - 1 and y < n - 2 and s[x + 1][y + 2] < 0:
            add(que, x + 1, y + 2, s, s[x][y] + 1)
        if x < n - 2 and y >= 1 and s[x + 2][y - 1] < 0:
            add(que, x + 2, y - 1, s, s[x][y] + 1)
        if x < n - 1 and y >= 2 and s[x + 1][y - 2] < 0:
            add(que, x + 1, y - 2, s, s[x][y] + 1)
        if x >= 2 and y < n - 1 and s[x - 2][y + 1] < 0:
            add(que, x - 2, y + 1, s, s[x][y] + 1)
        if x >= 1 and y < n - 2 and s[x - 1][y + 2] < 0:
            add(que, x - 1, y + 2, s, s[x][y] + 1)
    q.write(str(s[a[2]][a[3]]))
