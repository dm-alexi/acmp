def diff(s, t):
    return sum(s[i] != t[i] for i in range(len(s)))
        
with open("input.txt", "r") as f, open("output.txt", "w") as q:
    s = f.readline().strip()
    n = int(f.readline())
    t = [diff(s, x) for x in f.read().split()]
    m = min(t) if n > 0 else 0
    k = [str(i + 1) for i in range(n) if t[i] == m]
    q.write(str(len(k)) + "\n" + " ".join(k))
