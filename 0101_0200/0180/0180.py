with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n, k = (int(x) for x in f.readline().split())
    d = dict()
    for i in range(9, 1, -1):
        v = 0
        while k % i == 0:
            k, v = k // i, v + 1
        if v:
            d[i] = v
    q.write("YES" if k == 1 and (not d or int("".join([str(x) * y for x, y in d.items()][::-1])) <= n) else "NO")
            
