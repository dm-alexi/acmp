def sq(n):
    while n > 9:
        s = 0
        while n > 0:
            s += n % 10
            n //= 10
        n = s
    return n
 
with open("input.txt", "r") as f, open("output.txt", "w") as q:
    s = [int(x) for x in list(f.readline().strip())]
    r = False
    if len(s) > 1:
        a, b = s[0], sum(s[1:])
        r = (sq(a) == sq(b))
        if not r:
            for i in range(1, len(s)):
                a += s[i]
                b -= s[i]
                r = (sq(a) == sq(b))
                if r:
                    break
    q.write("YES" if r else "NO")
