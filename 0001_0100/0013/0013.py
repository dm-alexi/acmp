with open("input.txt", "r") as f, open("output.txt", "w") as q:
    s, t = f.read().split()
    b = [0, 0]
    for i, k in enumerate(s):
        if k in t:
            if t.index(k) == i:
                b[0] += 1
            else:
                b[1] += 1
    q.write(str(b[0]) + ' ' + str(b[1]))
