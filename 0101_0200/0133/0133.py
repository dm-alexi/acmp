from queue import PriorityQueue
with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n = int(f.readline().strip())
    p = [int(x) for x in f.readline().split()]
    s = [-1 for i in range(n)]
    t = [[-1 if i != j else 0 for i in range(n)] for j in range(n)]
    for i in range(int(f.readline().strip())):
        a, b = (int(x) - 1 for x in f.readline().split())
        t[a][b] = p[a]
        t[b][a] = p[b]
    que = PriorityQueue()
    que.put((0, 0))
    while not que.empty() and s[n - 1] < 0:
        dist, num = que.get()
        s[num] = dist
        for i in range(n):
            if s[i] < 0 and t[num][i] >= 0:
                que.put((t[num][i] + dist, i))
    q.write(str(s[n - 1]))
    
