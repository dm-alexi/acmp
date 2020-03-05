with open("input.txt", "r") as f, open("output.txt", "w") as q:
    f.readline()
    l = list(map(lambda x, y : x * y, (int(x) for x in f.readline().split()), (int(x) for x in f.readline().split())))
    q.write(str(l.index(max(l)) + 1))
