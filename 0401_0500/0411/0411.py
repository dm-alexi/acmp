with open("input.txt", "r") as f, open("output.txt", "w") as q:
    a, b, c = (int(x) for x in f.read().split())
    d = b * b - 4 * a * c
    if a == 0:
        r = "-1" if b == c == 0 else "0" if b == 0 != c else f"1\n{-c / b}"
    else:
        r = "0" if d < 0 else f"1\n{-b / (2 * a)}" if d == 0 else f"2\n{(-b - d ** 0.5) / (2 * a)}\n{(-b + d ** 0.5) / (2 * a)}"
    q.write(r)
