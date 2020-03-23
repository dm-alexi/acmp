with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n = int(f.readline())
    q.write(f"{12 if n % 400 == 0 or (n % 100 and n % 4 == 0) else 13}/09/{n:04d}")
