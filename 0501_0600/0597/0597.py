with open("input.txt", "r") as f, open("output.txt", "w") as q:
    s = [int(x) for x in f.readline().split()]
    q.write("YES" if s[0] >= s[1] + s[2] else "NO")
