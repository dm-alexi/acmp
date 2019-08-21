with open("input.txt", "r") as f, open("output.txt", "w") as q:
    m, t = 0, 0
    for x in f.readline():
        if x == '0':
            t += 1
        else:
            if t > m:
                m = t;
            t = 0
    q.write(str(m))
