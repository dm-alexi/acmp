with open("input.txt", "r") as f, open("output.txt", "w") as q:
    a, b, c = (int(x) for x in f.readline().split())
    s = ""
    if (a, b, c) == (0, 0, 0):
        s = "0"
    else:
        if a:
            s = str(a) + "+" if b > 0 else str(a)
        if b:
            s += str(b) + "x" if abs(b) > 1 else "-x" if b < 0 else "x"
        if c > 0 and (a or b):
            s += "+"
        if c:
            s += str(c) + "y" if abs(c) > 1 else "-y" if c < 0 else "y"
    q.write(s)
