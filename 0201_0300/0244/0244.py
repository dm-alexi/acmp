with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n, k = (int(x) for x in f.readline().split())
    m = 0
    d = [-1, -1]
    s = f.read().split()
    for i in range(k, n):
        if s[i] != s[i - k]:
            if m > 1:
                m = 3
                break
            d[m] = i
            m += 1
    if m > 2 or (m == 1 and d[0] >= 2 * k and n - d[0] >= k) or (m == 2 and d[1] - d[0] != k):
        q.write("FAIL")
    else:
        q.write("OK\n{}".format(d[0] % k + 1 if m == 1 and d[0] < 2 * k else d[0] + 1))
