def layer(n, k):
    if n > k * (k + 1) // 2:
        return 0
    if n < 3 or n == k * (k + 1) // 2:
        return 1
    if k > n:
        k = n
    d = 0
    while k >= n - k * (k + 1) // 2:
        d += layer(n - k, k - 1)
        k -= 1
    return d

with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n = int(f.read())
    q.write(str(layer(n, n)))
