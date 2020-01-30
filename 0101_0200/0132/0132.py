from queue import PriorityQueue
with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n, a, b = (int(x) - 1 for x in f.readline().split())
    n += 1
    m = [[int(x) for x in f.readline().split()] for i in range(n)]
    s = [-1 for i in range(n)]
    que = PriorityQueue()
    que.put((0, a))
    while not que.empty() and s[b] < 0:
        dist, num = que.get()
        s[num] = dist
        for i in range(n):
            if s[i] < 0 and m[num][i] >= 0:
                que.put((m[num][i] + dist, i))
    q.write(str(s[b]))
    
