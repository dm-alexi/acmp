with open("input.txt", "r") as f, open("output.txt", "w") as q:
    x = int(f.read())
    q.write(str(sum(i for i in range(1, x // 2 + 1) if x % i == 0) + x))
