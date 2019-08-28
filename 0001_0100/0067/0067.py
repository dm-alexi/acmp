with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n = int(f.readline())
    p = []
    for i in range(n):
        r = 0
        for x in (int(x) for x in f.readline().strip().split('.')):
            r = r * 256 + x
        p.append(r)
    for i in range(int(f.readline())):    
        s, t = [x.split('.') for x in f.readline().split()]
        a = b = 0
        for x in (int(x) for x in s):
            a = a * 256 + x
        for x in (int(x) for x in t):
            b = b * 256 + x
        q.write(str(sum(1 for j in p if a & j == b & j)) + "\n")           
        
