with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n = int(f.readline())
    s = [int(x) for x in f.readline().split()]
    k = sorted(s)
    ind = 1
    for i in range(1, n):
        if k[i] - k[i - 1] < k[ind] - k[ind - 1]:
            ind = i
    q.write("{}\n{} {}".format(k[ind] - k[ind - 1], s.index(k[ind - 1]) + 1, s.index(k[ind]) + 1))
