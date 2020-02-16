with open("input.txt", "r") as f, open("output.txt", "w") as q:
    p = [int(x) for x in f.read().split()[1:]]
    p.sort()
    s = 0
    for x in p:
        if x - 1 <= s:
            s += x
        else:
            break
    q.write(str(s + 1))
