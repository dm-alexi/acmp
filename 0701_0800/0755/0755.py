with open("input.txt", "r") as f, open("output.txt", "w") as q:
    a, b, c = (int(x) for x in f.readline().split())
    q.write("Impossible" if a + b < c else f"{a + b - c}")
