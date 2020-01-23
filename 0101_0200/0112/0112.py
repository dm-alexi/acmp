def countinv(p, n):
    i = j = r = 0
    if n <= 1:
        return 0
    a = p[:n // 2]
    b = p[n // 2:]
    r += countinv(a, n // 2) + countinv(b, n - n // 2)
    while i < n // 2 or j < n - n // 2:
        if j == n - n // 2 or (i < n // 2 and a[i] < b[j]):
            p[i + j] = a[i]
            i += 1
        else:
            p[i + j] = b[j]
            j += 1
            r += n // 2 - i
    return r
 
with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n, k = (int(x) for x in f.readline().split())
    m = 0
    while k:
        k -= 1
        p = [int(x) for x in f.readline().split()]
        m += countinv(p, n)
    q.write(str(m))
