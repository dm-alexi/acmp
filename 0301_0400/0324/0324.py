with open("input.txt", "r") as f, open("output.txt", "w") as q:
    s = f.readline().strip()
    q.write("YES" if s[0] == s[3] and s[1] == s[2] else "NO")
