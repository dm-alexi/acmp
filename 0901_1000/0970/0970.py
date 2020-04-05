with open("input.txt", "r") as f, open("output.txt", "w") as q:
    a, b, c = (int(x) for x in f.read().split())
    q.write("YES" if a + b == c or a + c == b or b + c == a else "NO")
