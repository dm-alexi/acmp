with open("input.txt", "r") as f, open("output.txt", "w") as q:
    s = [int(x) for x in f.read().split()]
    if s[0] * s[1] == s[2]:
        q.write("YES")
    else:
        q.write("NO")
