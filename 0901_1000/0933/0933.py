with open("input.txt", "r") as f, open("output.txt", "w") as q:
    a, b, c, t = (int(x) for x in f.read().split())
    q.write(str(t * b if t <= a else a * b + (t - a) * c))
