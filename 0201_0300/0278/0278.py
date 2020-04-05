with open("input.txt", "r") as f, open("output.txt", "w") as q:
    s, t = (x.strip() for x in f.readlines())
    ans = "YES"
    for x in s:
        c = t.find(x)
        if c == -1:
            ans = "NO"
            break
        t = t[c + 1:]
    q.write(ans)
