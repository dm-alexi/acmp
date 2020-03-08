with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n, m = (int(x) for x in f.readline().split())
    a = "YES"
    s = [4 if c == 'R' else 2 if c == 'G' else 1 if c == 'B' else 0 for c in ''.join(f.readline().strip() for i in range(n))]
    p = [int(x) for x in f.read().split()]
    for i in range(m * n):
        if s[i] and not s[i] & p[i]:
            a = "NO"
            break
    q.write(a)
