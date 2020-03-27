with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n = int(f.readline())
    m = float(f.readline())
    x, y = 30.0, 4000.0
    for i in range(n - 1):
        p, s = f.readline().split()
        p = float(p)
        if ((s == 'closer' and p < m) or (s == 'further' and p > m)) and y > p + (m - p) / 2:
            y = p + (m - p) / 2
        elif ((s == 'closer' and p > m) or (s == 'further' and p < m)) and x < m + (p - m) / 2:
            x = m + (p - m) / 2
        m = p
    q.write(f"{x} {y}")
