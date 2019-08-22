with open("input.txt", "r") as f, open("output.txt", "w") as q:
    q.write(str(2 ** int(f.read())))
