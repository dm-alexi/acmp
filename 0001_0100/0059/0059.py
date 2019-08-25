with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n, k = (int(x) for x in f.read().split())
    m, s = 1, 0
    while n:
        i = n % k
        s += i
        m *= i
        n //= k
    q.write(str(m - s))

        
    
           
        
