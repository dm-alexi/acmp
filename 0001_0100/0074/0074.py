with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n, k = (int(x) for x in f.read().split())
    s = 0
    if k == 1:
        s = n
    else:
        while k % 2:
            n //= 2
            s += n
            k = k // 2 + 1
    q.write(str(s + k // 2))
