with open("input.txt", "r") as f, open("output.txt", "w") as q:
    s = f.read().split()[1:]
    c, r = 3, 0
    for x in s:
        if x == "1":
            r += c
            c += 1
        else:
            c = c - 3 if c > 6 else 3
    q.write(str(r))
