with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n = int(f.readline())
    while n:
        n -= 1
        s = "YES\n"
        a, b = (int(x) for x in f.readline().split())
        p1 = [int(x) for x in f.readline().split()]
        for i in range(a - 1):
            p2 = [int(x) for x in f.readline().split()]
            for j in range(b - 1):
                if ((sum(p1[j : j + 2]) + sum(p2[j : j + 2])) in (0, 4)):
                    s = "NO\n"
                    break
            p1 = p2
        q.write(s)

        
    
           
        
