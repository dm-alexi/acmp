with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n = int(f.read())
    s, a = 0, 1
    for i in range(1, n + 1):
        a *= i
        s += a
    q.write(str(s))
