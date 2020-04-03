with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n = int(f.read())
    q.write(f"{n // 24 * 13} {n // 6} {n // 24 * 7}")
