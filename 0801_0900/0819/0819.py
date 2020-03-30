with open("input.txt", "r") as f, open("output.txt", "w") as q:
    a, b, c = (int(x) for x in f.readline().split())
    q.write(f"{2 * (a * b + a * c + b * c)} {a * b * c}")
