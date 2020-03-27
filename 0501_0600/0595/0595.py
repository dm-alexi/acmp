with open("input.txt", "r") as f, open("output.txt", "w") as q:
    s, t = (x.strip() for x in f.readlines())
    n = len(s)
    ans = (len(t) == n)
    if ans:
        p = [0]
        k = 0
        for i in range(1, n):
            while k > 0 and t[i] != t[k]:
                k = p[k - 1]
            if t[i] == t[k]:
                k += 1
            p.append(k)
        k = 0
        for i in range(n):
            while k > 0 and t[k] != s[i]:
                k = p[k - 1]
            if t[k] == s[i]:
                k += 1
        ans = (k == n or t[k:] == s[n - 1 - k::-1])
    q.write(f"Yes\n{n - k}" if ans else "No")
