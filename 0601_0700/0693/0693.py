with open("input.txt", "r") as f, open("output.txt", "w") as q:
    p = {i:0 for i in "abcdefghijklmnopqrstuvwxyz"}
    s, t = f.readline().split()
    r = (len(s) == len(t))
    if r:
        for i in range(len(s)):
            p[s[i].lower()] += 1
            p[t[i].lower()] -= 1
        r = all(x == 0 for x in p.values())
    q.write("Yes" if r else "No")
