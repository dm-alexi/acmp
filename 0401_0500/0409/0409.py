with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n = int(f.readline())
    s = [int(x) for x in f.readline().split()]
    q.write("{:.6f}".format(((s[0] + s[-1]) / 2 + sum(s[1 : n - 1])) / (n - 1)))
