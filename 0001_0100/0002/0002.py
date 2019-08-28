with open("input.txt", "r") as f, open("output.txt", "w") as q:
    a = int(f.read())
    q.write(str((1 + a) * a // 2 if a > 0 else (1 - a) * a // 2 + 1))
