with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n = int(f.read())
    a = [0, 2, 3, 4, 7, 13]
    b = [0, 1, 5, 6, 8, 9, 10, 11, 12]
    for i in range(6, n + 1):
        a.append(b[i - 1] + b[i - 3])
        if len(b) < n + 1:
            b.extend(list(range(a[-2] + 1, a[-1])))
    q.write("{}\n{}".format(a[n], b[n]))
        
