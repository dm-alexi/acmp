with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n, m, k = (int(x) for x in f.readline().split())
    s = [[list(f.readline().strip()) for i in range(n)], [[None for j in range(m)] for i in range(n)]]
    for l in range(k):
        for i in range(n):
            for j in range(m):
                count = sum(x == '*' for x in (s[l % 2][(i - 1 + n) % n][(j - 1 + m) % m], s[l % 2][(i - 1 + n) % n][j], \
                    s[l % 2][(i - 1 + n) % n][(j + 1) % m], s[l % 2][i][(j - 1 + m) % m], s[l % 2][i][(j + 1) % m], \
                    s[l % 2][(i + 1) % n][(j - 1 + m) % m], s[l % 2][(i + 1) % n][j], s[l % 2][(i + 1) % n][(j + 1) % m]))
                s[(l + 1) % 2][i][j] = '*' if count == 3 or (s[l % 2][i][j] == '*' and count == 2) else '.'
    q.write("\n".join(''.join(s[k % 2][i][j] for j in range(m)) for i in range(n)))
