with open("input.txt", "r") as f, open("output.txt", "w") as q:
    a = int(f.read())
    if (a > 0):
        q.write(str((1 + a) * a // 2))
    else:
        q.write(str((1 - a) * a // 2 + 1))
