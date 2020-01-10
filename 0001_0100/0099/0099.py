from collections import deque
def add_one(a, p, b, queue):
    if a[b] == '.':
        a[b] = int(a[p] + 1)
        queue.append(b)
    return a[b] == '2'
    
def add_neighbors(a, p, queue, h, m, n):
    if (p % n > 0 and add_one(a, p, p - 1, queue)) \
    or (p % n < n - 1 and add_one(a, p, p + 1, queue)) \
    or (p % (m * n) // n > 0 and add_one(a, p, p - n, queue)) \
    or (p % (m * n) // n < m - 1 and add_one(a, p, p + n, queue)) \
    or (p // (m * n) < h - 1 and add_one(a, p, p + m * n, queue)):
        return a[p] + 1
    return 0

with open("input.txt", "r") as f, open("output.txt", "w") as q:
    h, m, n = (int(x) for x in f.readline().split())
    a = [x for x in f.read() if x != '\n' and x != ' ']
    queue = deque()
    for i in range(h * m * n):
        if a[i] == '1':
            a[i] = 0;
            queue.append(i)
            break
    while True:
        res = add_neighbors(a, queue.popleft(), queue, h, m, n)
        if res:
            break;
    q.write(str(res * 5))
