def derange(n):
    return 1 if n == 0 else 0 if n == 1 else n * derange(n - 1) + (-1)**n

def c(n, k):
    a = 1
    b = 1
    while n > k:
        a *= n
        b *= n - k
        n -= 1
    return a // b

with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n, k = map(int, f.readline().split())
    q.write(str(c(n, k) * derange(n - k)))
