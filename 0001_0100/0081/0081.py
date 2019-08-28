with open("input.txt", "r") as f, open("output.txt", "w") as q:
    s = [int(x) for x in f.read().split()[1:]]
    q.write("{} {}".format(min(s), max(s)))
