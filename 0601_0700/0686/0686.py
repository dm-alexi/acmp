with open("input.txt", "r") as f, open("output.txt", "w") as q:
    f.readline()
    s = [int(x) for x in f.readline().split()]
    s.sort()
    a = s[::2]
    a.extend(s[1::2][::-1])
    q.write(' '.join(str(x) for x in a))
