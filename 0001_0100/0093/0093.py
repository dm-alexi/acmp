def comp(s, t):
    n = len(s)
    k = sum(1 for i in range(n) if s[i] != t[i]) if len(t) == n else 0
    return 1 if k == 1 else 0            

with open("input.txt", "r") as f, open("output.txt", "w") as q:
    s, t = [], []
    for i in range(int(f.readline())):
        s.append(f.readline().strip())
    for i in range(int(f.readline())):
        t.append(f.readline().strip())
    q.write(' '.join([str(sum(comp(a, b) for b in t)) for a in s]))
        
