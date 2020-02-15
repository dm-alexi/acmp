with open("input.txt", "r") as f, open("output.txt", "w") as q:
    f.readline()
    s = f.readline().strip()
    i = s.find(' 1 ')
    q.write(s[i + 1:] + ' ' + s[:i] if i > -1 else s if s[:2] == '1 ' else '1 ' + s[:-1])
