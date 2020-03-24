with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n = int(f.read())
    q.write("YES" if n > 0 and not (n & (n - 1)) else "NO")
