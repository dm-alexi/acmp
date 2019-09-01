def decdiv(n, m):
    int_part = str(n // m)
    ans = ""
    l = dict()
    n %= m
    l[n] = 0
    i = 1
    if n == 0:
        return int_part
    while True:
        if n == 0:
            return "{}.{}".format(int_part, ans)
        d, n = divmod(n * 10, m)
        ans += str(d)
        if n in l:
            return "{}.{}({})".format(int_part, ans[:l[n]], ans[l[n]:])
        else:
            l[n] = i
            i += 1

with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n, m = (int(x) for x in f.read().strip().split('/'))
    q.write(decdiv(n, m))
