with open("input.txt", "r") as f, open("output.txt", "w") as q:
    q.write(str(int(((1 + 8 * int(f.readline())) ** 0.5 - 1) / 2)))
