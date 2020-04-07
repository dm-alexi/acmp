with open("input.txt", "r") as f, open("output.txt", "w") as q:
    a, b, n = (int(x) for x in f.read().split())
    q.write(str(a + (n - 1) * (b - a)))
