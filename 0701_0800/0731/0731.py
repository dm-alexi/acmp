from math import floor, ceil
with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n = int(f.readline())
    d = []
    s, ps = 0, 0
    for i in range(n):
        line = f.readline().split()
        d.append([line[0] == '+', int(line[1]), None])
        s += int(line[1])
    for x in d:
        x[2] = ceil(100 * x[1] / s) if x[0] else floor(100 * x[1] / s)
        ps += x[2]
    for x in d:
        if ps == 100:
            break
        elif ps < 100 and not x[0] and 100 * x[1] % s:
            x[2], ps = x[2] + 1, ps + 1
        elif ps > 100 and x[0] and 100 * x[1] % s:
            x[2], ps = x[2] - 1, ps - 1
    q.write('\n'.join(str(x[2]) for x in d))
