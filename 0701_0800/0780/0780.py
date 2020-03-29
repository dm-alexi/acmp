with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n = int(f.readline())
    q.write(f"{int((1 + 8 * n) ** 0.5 - 1) // 2}")
