with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n, k = map(int, f.read().split())
    r = 1 if n == k else 0
    if r == 0 and n % 2 == k % 2:
        p = [0] * k
        p[0] = 1
        for i in range(2, k + 1):
            t = p[1]
            for j in range(i % 2 + 1, k - 1, 2):
                p[j] = p[j - 1] + p[j + 1]
            p[0] = t
        r = p[n - 1]
    q.write(str(r))
