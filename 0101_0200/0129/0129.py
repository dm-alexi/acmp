from collections import deque
def add(s, que, pos, val):
    que.append(pos)
    s[pos] = val + 1
    
with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n, m = (int(x) for x in f.readline().split())
    s = [int(x) - 1 for x in f.read().split()]
    que = deque(i for i in range(m * n) if s[i] == 0)
    while len(que):
        x = que.popleft()
        if x % m > 0 and s[x - 1] < 0:
            add(s, que, x - 1, s[x])
        if (x + 1) % m > 0 and s[x + 1] < 0:
            add(s, que, x + 1, s[x])
        if x // m  > 0 and s[x - m] < 0:
            add(s, que, x - m, s[x])
        if x // m < n - 1 and s[x + m] < 0:
            add(s, que, x + m, s[x])
    q.write('\n'.join(' '.join(str(s[i * m + j]) for j in range(m)) for i in range(n)))
