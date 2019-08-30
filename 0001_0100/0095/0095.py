with open("input.txt", "r") as f, open("output.txt", "w") as q:
    s = f.read().strip()
    k = 1 if len(s) > 1 else 0
    n = sum(int(x) for x in s)
    while n > 9:
        k += 1
        h = 0
        while n:
            h += n % 10
            n //= 10
        n = h
    q.write("{} {}".format(n, k))
