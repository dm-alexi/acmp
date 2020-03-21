with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n = 5 * (int(f.read()) - 1)
    q.write("NO" if n > 720 else f"{n // 60} {n % 60}")
