with open("input.txt", "r") as f, open("output.txt", "w") as q:
    s = f.readline().strip()
    l = "abcdefgh"
    n = "12345678"
    s = [l.find(s[0]), n.find(s[1])]
    ans = []
    if s[0] > 1 and s[1] > 0:
        ans.append(l[s[0] - 2] + n[s[1] - 1])
    if s[0] > 1 and s[1] < 7:
        ans.append(l[s[0] - 2] + n[s[1] + 1])
    if s[0] > 0 and s[1] > 1:
        ans.append(l[s[0] - 1] + n[s[1] - 2])
    if s[0] > 0 and s[1] < 6:
        ans.append(l[s[0] - 1] + n[s[1] + 2])
    if s[0] < 7 and s[1] > 1:
        ans.append(l[s[0] + 1] + n[s[1] - 2])
    if s[0] < 7 and s[1] < 6:
        ans.append(l[s[0] + 1] + n[s[1] + 2])
    if s[0] < 6 and s[1] > 0:
        ans.append(l[s[0] + 2] + n[s[1] - 1])
    if s[0] < 6 and s[1] < 7:
        ans.append(l[s[0] + 2] + n[s[1] + 1])    
    q.write("\n".join(ans))
