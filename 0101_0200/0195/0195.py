with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n, a, b = (int(x) for x in f.read().split())
    q.write(str(2 * n * a * b))
