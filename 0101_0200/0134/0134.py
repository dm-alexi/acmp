from queue import PriorityQueue
with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n = int(f.readline())
    d, v = (int(x) - 1 for x in f.readline().split())
    s = [-1 for i in range(n)]
    t = [[] for i in range(n)]
    for i in range(int(f.readline())):
        a, t1, b, t2 = (int(x) for x in f.readline().split())
        a, b = a - 1, b - 1
        t[a].append((b, t1, t2))
    que = PriorityQueue()
    que.put((0, d))
    while not que.empty() and s[v] < 0:
        time, num = que.get()
        s[num] = time
        for r in t[num]:
            if s[r[0]] < 0 and time <= r[1]:
                que.put((r[2], r[0]))
    q.write(str(s[v]))
