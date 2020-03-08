with open("input.txt", "r") as f, open("output.txt", "w") as q:
    s = f.readline().strip()
    r = True
    p = [(ord(s[i]) - ord('A'), i + 1) for i in range(26)]
    p.sort()
    for i in range(26):
        if p[i][0] < i:
            r = False
            break
    q.write("YES\n" + ' '.join(str(x[1]) for x in p) if r else "NO")

        
