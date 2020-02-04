from queue import PriorityQueue
with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n, m = (int(x) for x in f.readline().split())
    s = [{i} for i in range(n)]
    k = 0
    res = 0
    que = PriorityQueue()
    for i in range(m):
        a, b, r = (int(x) for x in f.readline().split())
        que.put((r, a - 1, b - 1))
    while k < n - 1:
        d = que.get()
        if s[d[1]].isdisjoint(s[d[2]]):
            s[d[1]].update(s[d[2]])
            for x in s[d[2]]:
                s[x] = s[d[1]]
            k += 1
            res += d[0]
    q.write(str(res))
