with open("input.txt", "r") as f, open("output.txt", "w") as q:
    w, h = map(int, f.readline().split())
    d = [1] * (w * h)
    f.readline()
    s = ([int(c) for c in x.split()] for x in f.read().split('\n')[:-1])
    for x in s:
        for i in range(x[1], x[3]):
            d[w * i + x[0] : w * i + x[2]] = [0] * (x[2] - x[0]) 
    q.write(str(sum(d)))
