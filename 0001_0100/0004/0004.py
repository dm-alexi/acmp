with open("input.txt", "r") as f, open("output.txt", "w") as q:
    a = int(f.read())
    q.write(f"{a}9{9 - a}")
