with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n = int(f.readline())
    i, u, s = 1, 1, 0
    while s + u < n:
        s += u
        i += 1
        u += 1 if i < 10 else 2 if i < 100 else 3
    n -= s
    if n >= 190:
        n -= 190
        n = 1 if n % 3 == 0 else n // 30 if n % 3 == 1 else n % 30 // 3
    elif n >= 10:
        n -= 10
        n = n % 20 // 2 if n % 2 else n // 20 + 1
    q.write(str(n))
        
