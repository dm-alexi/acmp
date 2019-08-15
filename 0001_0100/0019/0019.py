with open("input.txt", "r") as f, open("output.txt", "w") as q:
    t = [(ord(x[0]) - ord('A'), int(x[1]) - 1) for x in f.readline().split()]
    a = 0
    for i in range(8):
        if i in (t[0][0], t[1][0]):
            a += 8
        else:
            for j in range(8):
                if j in (t[0][1], t[1][1]) or abs(t[0][0] - i) == abs(t[0][1] - j) \
                   or abs((t[2][0] - i) * (t[2][1] - j)) == 2 or (i, j) == t[2]:
                    a += 1
    q.write(str(a - 3))
