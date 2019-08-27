with open("input.txt", "r") as f, open("output.txt", "w") as q:
    f.readline()
    s = [int(x) for x in (set(x for x in f.readline().split()) & set(x for x in f.readline().split()))]
    s.sort()
    q.write(" ".join(str(x) for x in s))
