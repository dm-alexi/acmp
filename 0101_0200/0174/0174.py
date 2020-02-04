with open("input.txt", "r") as f, open("output.txt", "w") as q:
    f.readline()
    p = [int(x) for x in f.readline().split()]
    p.sort()
    s = int(f.readline())
    for x in p:
        if s < x:
            s = (s + x) / 2
    q.write("{:f}".format(s))

