with open("input.txt", "r") as f, open("output.txt", "w") as q:
    c, n = f.read().split()
    n = int(n)
    d = 1
    l, r = [], []
    while n:
        if n % 3 == 1:
            r.append(str(d))
        elif n % 3 == 2:
            l.append(str(d))
            n += 3
        n //= 3
        d *= 3
    if c == 'R':
        l, r = r, l
    q.write("L:" + ' '.join(l) + "\nR:" + ' '.join(r))
