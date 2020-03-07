with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n = int(f.readline())
    r, m, k = n, n, 0
    while m >> 1:
        k += 1
        m >>= 1
    m = 1 << k
    for i in range(k):
        n = (n >> 1) | m if n & 1 else n >> 1
        if n > r:
            r = n
    q.write(str(r))
        
        
