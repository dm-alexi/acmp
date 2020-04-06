with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n = int(f.read())
    s = []
    while n:
        k = n % 3 if n % 3 else 3
        s.insert(0, str(k))
        n = (n - k) // 3
    q.write(''.join(s))
