with open("input.txt", "r") as f, open("output.txt", "w") as q:
    a, b = (int(x) for x in f.readline().split())
    c = int((a * b) ** 0.5)
    q.write(str(c) if c * c == a * b else "0")
