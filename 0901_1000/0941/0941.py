with open("input.txt", "r") as f, open("output.txt", "w") as q:
    a, b = (int(x, base = 3) for x in f.read().split())
    q.write(str(a + b))
