with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n = int(f.readline())
    p = [int(i[0]) * 3600 + int(i[1]) * 60 + int(i[2]) for i in (x.split() for x in f.readlines())]
    p.sort()
    for x in p:
        q.write("{} {} {}\n".format(x // 3600, x % 3600 // 60, x % 60))
