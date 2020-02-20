def check(s):
    p = [(s[2 * i + 1], s[2 * i + 2]) for i in range(s[0])]
    p.sort()
    if p[0][0] > 0 or p[s[0] - 1][1] < 10000 or (s[0] > 1 and p[1][0] ==0):
        return 0
    for i in range(1, s[0]):
        if p[i - 1][1] < p[i][0] or p[i - 1][1] >= p[i][1]:
            return 0
    for i in range(2, s[0]):
        if p[i][0] <= p[i - 2][1]:
            return 0
    return 1        

with open("input.txt", "r") as f, open("output.txt", "w") as q:
    for i in range(int(f.readline())):
        q.write("Accepted\n" if check([int(x) for x in f.readline().split()]) else "Wrong Answer\n")
