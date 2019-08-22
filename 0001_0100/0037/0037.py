with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n, k = f.readline().split()
    n = int(n)
    k = round(float(k) * 1000)
    while n:
        a, b, c, d = map(int, f.readline().split())
        if 1000000 * (c * c + d * d) > k * k * (a * a + b * b):
            break
        n -= 1
    q.write("No" if n else "Yes")
