with open("input.txt", "r") as f, open("output.txt", "w") as q:
    s = f.read().strip()
    l = "ABCDEFGH"
    n = "12345678"
    if len(s) != 5 or not (s[0] in l and s[3] in l and s[1] in n and s[4] in n and s[2]=='-'):
        s = "ERROR"
    else:
        p = (abs(l.index(s[0]) - l.index(s[3])), abs(n.index(s[1]) - n.index(s[4])))
        if p == (1, 2) or p == (2, 1):
            s = "YES"
        else:
            s = "NO"
    q.write(s)
