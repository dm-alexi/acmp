with open("input.txt", "r") as f, open("output.txt", "w") as q:
    f.readline()
    m, k = 0, 0
    for a in (int(x) for x in f.readline().split()):
        if a <= 0:
            k = 0
        else:
            k += 1
            if k > m:
                m = k
    q.write(str(m))
