with open("input.txt", "r") as f, open("output.txt", "w") as q:
    s, t = f.read().split()
    a = sum(1 for i in range(4) if s[i] in t and t.index(s[i]) == i)
    b = sum(1 for i in range(4) if s[i] in t) - a
    q.write(str(a) + ' ' + str(b))
