with open("input.txt", "r") as f, open("output.txt", "w") as q:
    s = f.read().split()[1:]
    d = sorted([(s.count(x), x) for x in set(s)], reverse = True)
    q.write(d[0][1] if len(d) == 1 or d[0][0] > d[1][0] else "0")
