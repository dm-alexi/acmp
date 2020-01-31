with open("input.txt", "r") as f, open("output.txt", "w") as q:
    a, b = f.read().split()
    q.write(str(int(a) % int(b)))
