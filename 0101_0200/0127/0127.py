from collections import deque
with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n = int(f.readline())
    m = [[int(x) for x in f.readline().split()] for i in range(n)]
    a, b = (int(x) - 1 for x in f.read().split())
    if a == b:
        q.write("0")
    else:
        que = deque(i for i in range(n) if m[a][i])
        while m[a][b] == 0 and len(que):
            x = que.popleft()
            for i in range(n):
                if m[x][i] and m[a][i] == 0:
                    m[a][i] = m[a][x] + 1
                    que.append(i)
        q.write(str(m[a][b]) if m[a][b] > 0 else "-1")
        
