with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n, k = f.read().split()
    n = int(n)
    k = len(k)
    g = n - k
    while g > 0:
        n *= g
        g -= k
    q.write(str(n))

        
