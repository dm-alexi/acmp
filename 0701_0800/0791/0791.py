with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n = int(f.readline())
    s = []
    if n > 8:
        s.append(n - 8)
    if n % 8 != 1:
        s.append(n - 1)
    if n % 8:
        s.append(n + 1)
    if n < 57:
        s.append(n + 8)
    q.write(' '.join(str(x) for x in s))
    
