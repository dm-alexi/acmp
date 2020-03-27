with open("input.txt", "r") as f, open("output.txt", "w") as q:
    s = f.readline().strip()
    d, i, n = 0, 0, len(s)
    while d < n - i:
        d = max(d, s.rindex(s[i]) - i)
        i += 1
    q.write(str(d))
