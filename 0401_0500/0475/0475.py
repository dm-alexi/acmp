with open("input.txt", "r") as f, open("output.txt", "w") as q:
    p = [int(x) for x in f.read().split()]
    n, l, r = len(p), min(p), max(p)
    k = (r - l) // (n - 1)
    q.write("Yes" if r == l or (len(set(p)) == n and (r - l) % (n - 1) == 0 and sum(1 for x in p if (x - l) % k == 0) == n) else "No")
