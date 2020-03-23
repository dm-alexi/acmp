with open("input.txt", "r") as f, open("output.txt", "w") as q:
    s, t = (list(x) for x in f.readline().split())
    n = len(s)
    q.write("YES" if len(t) == n and False not in (s[i] != t[i] for i in range(n)) and sorted(s) == sorted(t) else "NO")
