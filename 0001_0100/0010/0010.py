with open("input.txt", "r") as f, open("output.txt", "w") as q:
    a, b, c, d = (int(x) for x in f.read().split())
    q.write(' '.join(str(x) for x in range(-100, 101) if a * x ** 3 + b * x ** 2 + c * x + d == 0))
