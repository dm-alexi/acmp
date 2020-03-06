def prefix(s):
    p = [0]
    k = 0
    for i in range(1, len(s)):
        while k > 0 and s[i] != s[k]:
            k = p[k - 1]
        if s[i] == s[k]:
            k += 1
        p.append(k)
    return p
    
with open("input.txt", "r") as f, open("output.txt", "w") as q:
    s = f.readline().strip()
    q.write(str(len(s) - prefix(s)[-1]))
    
