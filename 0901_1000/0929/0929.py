with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n = int(f.read())
    q.write(f"{n // 6 + 7 - n % 6 if n % 6 else n // 6} {n * 6}")
