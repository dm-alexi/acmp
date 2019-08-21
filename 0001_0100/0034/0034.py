with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n, k = map(int, f.readline().split())
    res = "NO"
    if n > k:
        s = f.readline()
        l = {int(s[:k]):0}
        for i in range(1, n - k + 1):
            d = int(s[i : k + i])
            if d in l:
                res = "YES"
                break
            l[d] = 0
    q.write(res)
