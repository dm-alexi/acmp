with open("input.txt", "r") as f, open("output.txt", "w") as q:
    r = 0
    for i in range(4):
        a, b = (int(x) for x in f.readline().split())
        r += a - b
    q.write("1" if r > 0 else "2" if r < 0 else "DRAW")
