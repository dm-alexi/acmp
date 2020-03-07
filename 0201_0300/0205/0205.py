with open("input.txt", "r") as f, open("output.txt", "w") as q:
    s = [int(x) for x in f.readline().split(':')]
    t = [int(x) for x in f.readline().split(':')]
    while len(t) < 3:
        t.insert(0, 0)
    for i in range(3):
        s[i] += t[i]
    s[1] += s[2] // 60
    s[2] %= 60
    s[0] += s[1] // 60
    s[1] %= 60
    d = s[0] // 24
    s[0] %= 24
    q.write("{:02d}:{:02d}:{:02d}+{} days".format(s[0], s[1], s[2], d) if d else "{:02d}:{:02d}:{:02d}".format(s[0], s[1], s[2]))
