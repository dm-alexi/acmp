with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n = f.readline().strip()
    s = sorted([f.readline().strip() for i in range(3)])
    q.write(n + ': ' + ', '.join(s))
