with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n = int(f.readline())
    q.write(str(0 if n == 1 else n if n % 2 else n // 2))
