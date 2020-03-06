with open("input.txt", "r") as f, open("output.txt", "w") as q:
    f.readline()
    p = [int(x) for x in f.readline().split() if int(x) % 2 == 0 and int(x) & 64]
    q.write(str(len(p)))
    if len(p):
        p.sort()
        q.write("\n" + ' '.join(str(x) for x in p))
