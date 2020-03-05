from queue import PriorityQueue
with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n, e = (int(x) for x in f.readline().split())
    e -= 1
    s = [-1 for i in range(n)]
    t = [[] for i in range(n)]
    for i in range(int(f.readline())):
        v = [int(x) for x in f.readline().split()]
        k, a, t1 = v[0], v[1] - 1, v[2]
        for j in range(3, 2 * k + 1, 2):
            t[a].append((v[j] - 1, t1, v[j + 1]))
            a = v[j] - 1
            t1 = v[j + 1]
    que = PriorityQueue()
    que.put((0, 0))
    while not que.empty() and s[e] < 0:
        time, num = que.get()
        s[num] = time
        for r in t[num]:
            if s[r[0]] < 0 and time <= r[1]:
                que.put((r[2], r[0]))
    q.write(str(s[e]))
