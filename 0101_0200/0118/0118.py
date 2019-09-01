def z(n, k):
    return 1 if n == 1 else 1 + (z(n - 1, k) + k - 1) % n

with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n, k = (int(x) for x in f.readline().split())
    q.write(str(z(n, k)))
