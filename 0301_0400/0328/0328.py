with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n = int(f.read()) + 1
    q.write(str((n * n * n - n) // 2))
