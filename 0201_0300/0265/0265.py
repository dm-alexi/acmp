with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n = int(f.readline())
    s = [[0 for i in range(8)] for j in range(8)]
    p = 0
    for i in range(n):
        y, x = (int(a) - 1 for a in f.readline().split())
        s[y][x] = 1
    for i in range(8):
        for j in range(8):
            if s[i][j]:
                if i == 0 or s[i - 1][j] == 0:
                    p += 1
                if i == 7 or s[i + 1][j] == 0:
                    p += 1
                if j == 0 or s[i][j - 1] == 0:
                    p += 1
                if j == 7 or s[i][j + 1] == 0:
                    p += 1
    q.write(str(p))
