with open("input.txt", "r") as f, open("output.txt", "w") as q:
    s = f.readline().strip()
    h, l, k = 0, 0, 0
    for c in s:
        if c == '1':
            k += 1
            if k > h:
                h += 1
        elif c == '2':
            k -= 1
            if k < l:
                l -= 1
    q.write(str(h - l + 1))
