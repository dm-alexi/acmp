with open("input.txt", "r") as f, open("output.txt", "w") as q:
    w, h = (int(x) for x in f.readline().split())
    s = [f.readline().strip() for i in range(h)]
    t = [f.readline().strip() for i in range(h)]
    p = f.readline().strip()
    q.write('\n'.join(''.join(p[0] if s[i][j] == '0' and t[i][j] == '0' else p[1] if s[i][j] == '0' and t[i][j] == '1' else p[2] if s[i][j] == '1' and t[i][j] == '0' else p[3] for j in range(w)) for i in range(h)))
        
