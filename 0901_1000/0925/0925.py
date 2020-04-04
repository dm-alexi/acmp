with open("input.txt", "r") as f, open("output.txt", "w") as q:
    l, n, a, b, c = (int(x) for x in f.read().split())
    q.write(str(min(a, b, c) if l == 2 else max(a + b + c - 2 * n, 0)))
