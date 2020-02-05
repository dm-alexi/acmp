with open("input.txt", "r") as f, open("output.txt", "w") as q:
    w, h, n = (int(x) for x in f.read().split())
    if w > h:
        w, h = h, w
    r = h if h > n * w else n * w
    l = int((w * h * n) ** 0.5)
    k = (r + l) // 2
    while (k // w) * (k // h) != n:
        if (k // w) * (k // h) > n:
            r, k = k, (k + l) // 2
        elif ((k + 1) // w) * ((k + 1) // h) >= n:
            k += 1
            break
        else:
            l, k = k + 1, (k + r) // 2
    while ((k - 1) // w) * ((k - 1) // h) >= n:
        k -= 1
    q.write(str(k))
            
