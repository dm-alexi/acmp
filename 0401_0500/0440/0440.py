def dist(a, b):
    return ((a[0] - b[0]) * (a[0] - b[0]) + (a[1] - b[1]) * (a[1] - b[1])) ** 0.5

with open("input.txt", "r") as f, open("output.txt", "w") as q:
    m = [[25 * i, 0, False] for i in range(5)]
    d = 0
    for s in f.readlines():
        a = [int(x) for x in s.split()]
        for x in m:
            if not x[2] and dist(a, x) <= 10:
                x[2] = True
                d += 1
                break
    q.write(str(d))
                
