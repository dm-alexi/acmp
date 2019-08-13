with open("input.txt", "r") as f, open("output.txt", "w") as q:
    s = [int(x) for x in f.read().split()]
    q.write(str(max(s)))
