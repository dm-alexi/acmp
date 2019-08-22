def play(p, l, r, t):
    if t[l][r] == None:
        t[l][r] = max(p[l] - play(p, l + 1, r, t), p[r] - play(p, l, r - 1, t))
    return t[l][r]

with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n = int(f.readline())
    p = [int(x) for x in f.readline().split()]
    t = [[None] * n for i in p]
    for i in range(n):
        t[i][i] = p[i]
    n = play(p, 0, n - 1, t)
    q.write("0" if n == 0 else "1" if n > 0 else "2")
