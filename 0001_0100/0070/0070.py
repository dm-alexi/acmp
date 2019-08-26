with open("input.txt", "r") as f, open("output.txt", "w") as q:
    s, n = f.read().split()
    n = int(n)
    l = len(s)
    t = ""
    if n > 0:
        while n and len(t) < 1023:
            n -= 1
            t += s
    else:
        n = -n
        t = s[: l // n] if l % n == 0 and s[: l // n] * n == s else "NO SOLUTION"
    q.write(t[:1023])
