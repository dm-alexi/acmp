with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n = int(f.readline())
    p = [int(x) for x in f.readline().split()]
    s = sum(p)
    for i in range(1, 1 << (n - 1)):
        if s == 0:
            break
        k = p[0]
        for j in range(1, n):
            k = k - p[j] if i & 1 else k + p[j]
            i >>= 1
        if abs(k) < s:
            s = abs(k)
    q.write(str(s))