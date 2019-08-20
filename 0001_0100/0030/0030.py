with open("input.txt", "r") as f, open("output.txt", "w") as q:
    s = [int(x) for x in f.readline().strip().split(':')]
    t = [int(x) for x in f.readline().strip().split(':')]
    p = [0] * 10
    while s <= t:
        for x in s:
            p[x // 10] += 1
            p[x % 10] += 1
        s[2] += 1
        if s[2] == 60:
            s[2] = 0
            s[1] += 1
            if s[1] == 60:
                s[1] = 0
                s[0] += 1
    for i in p:
        q.write(str(i) + '\n')
