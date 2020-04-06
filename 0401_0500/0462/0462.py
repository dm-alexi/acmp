with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n = int(f.read())
    q.write(str(n - (n // 2 + n // 3 - n // 6 + n // 5 - n // 15 - n // 10 + n // 30)))
