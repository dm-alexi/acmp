with open("input.txt", "r") as f, open("output.txt", "w") as q:
    s = f.readline().strip()
    n = len(s)
    q.write("NO SOLUTION" if s == s[0] * n else s[1:] if s == s[::-1] else s)
