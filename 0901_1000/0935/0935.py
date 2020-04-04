with open("input.txt", "r") as f, open("output.txt", "w") as q:
    a, b, c, d = (int(x) for x in f.read().split())
    q.write("YES" if (a + b) % 2 == (c + d) % 2 else "NO")
