with open("input.txt", "r") as f, open("output.txt", "w") as q:
    t = "ABCEHKMOPTXY"
    n = int(f.readline())
    for i in range(n):
        s = f.readline().strip()
        q.write("Yes\n" if len(s) == 6 and s[0] in t and s[4] in t and s[5] in t and s[1:4].isdigit() else "No\n")
