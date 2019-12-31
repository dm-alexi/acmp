with open("input.txt", "r") as f, open("output.txt", "w") as q:
    m, n = (int(x) for x in f.read().split())
    if m == 1 or n == 1:
        k = 4 * m * n
    elif m % 2 and n % 2:
        k = 2 * (m + n + m * n - 1)
    else:
        k = 2 * (m + n + m * n)
    q.write(str(k))
