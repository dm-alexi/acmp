with open("input.txt", "r") as f, open("output.txt", "w") as q:
    q.write(str(sum(int(x) for x in f.read().split())))
