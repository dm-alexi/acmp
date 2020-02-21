with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n = int(f.readline())
    a, b, i = 1, 2, 3
    while b < n:
        a, b, i = b, a + b, i + 1
    q.write('0' if b > n else "1\n" + str(i))
        
