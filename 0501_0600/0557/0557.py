with open("input.txt", "r") as f, open("output.txt", "w") as q:
    m, n = (int(a) for a in f.readline().split())
    y, x = (int(a) - 1 for a in f.readline().split())
    p = int(f.readline())
    matrix = [None for i in range(n)]
    f.readline()
    for i in range(n):
        s = f.readline()
        if i == y:
            row = [int(a) for a in s.split()]
    for k in range(m - 1):
        f.readline()
        for i in range(n):
            matrix[i] = [int(a) for a in f.readline().split()]
        row = [sum(row[j] * matrix[j][i] for j in range(n)) % p for i in range(n)]
    q.write(str(row[x]))
