with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n, v, l = (int(x) for x in f.readline().split())
    q.write("{:.2f}".format(l / v * 60 + sum(int(x) for x in f.readline().split()[1::2])))
