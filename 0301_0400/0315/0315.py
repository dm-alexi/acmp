with open("input.txt", "r") as f, open("output.txt", "w") as q:
    t = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    s = f.readline().strip()
    n = 1
    for x in s:
        k = t.find(x) + 1
        if k > n:
            n = k
        elif k == 0:
            n = -1
            break
    q.write('2' if n == 1 else str(n))
