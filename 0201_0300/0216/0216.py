from queue import PriorityQueue
with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n = int(f.readline())
    que = PriorityQueue()
    for x in f.read().split():
        que.put(-int(x))
    k = 0
    while que.qsize() > 1:
        a, b = que.get() + 1, que.get() + 1
        if a:
            que.put(a)
        if b:
            que.put(b)
        k += 1
    q.write(str(k))
