with open("input.txt", "r") as f, open("output.txt", "w") as q:
    a = 1
    for c in f.read().strip():
        if c == 'A' and a != 3:
            a = 3 - a
        elif c == 'B' and a != 1:
            a = 5 - a
        elif c == 'C' and a != 2:
            a = 4 - a
    q.write(str(a))
