with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n, m = (int(x) for x in f.readline().split())
    base = []
    ans = []
    for i in range(n):
        s = [int(x) for x in f.readline().split()]
        if s[1]:
            base.append(tuple(s))
    if base:
        base.sort(key = lambda a : (-a[1], a[2]))
        ans.extend(x[0] for x in base if x[1] == base[0][1] or x[1] > base[len(base) // 2 - 1][1])
    for i in range(m):
        s = f.readline().split()
        if s[1] != '0':
            ans.append(int(s[0]))
    ans.sort()
    q.write(str(len(ans)) + "\n" + " ".join(str(x) for x in ans))
        
            
       
    
