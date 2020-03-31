with open("input.txt", "r") as f, open("output.txt", "w") as q:
    a, b = (int(x) for x in f.readline().split())
    s = f.readline()
    q.write(str(b) if (s[0] == 'f' and b < a) or (s[0] == 'h' and b > a) or s[0] == 'a' else str(a))
