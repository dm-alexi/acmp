with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n, m, k = (int(x) for x in f.readline().split())
    q.write(f"{n * m}" if m < k else f"{n * (k - 1 + m // k)}")
