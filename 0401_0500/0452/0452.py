def restore(s):
    i = 0
    while i < 253:
        if s[i] == 0 and s[i + 1] == 1 and s[i + 2] == 1:
            s[i], s[i + 1], s[i + 2] = 1, 0, 0
            i = i - 3 if i > 2 else 0
        else:
            i += 1

with open("input.txt", "r") as f, open("output.txt", "w") as q:
    a = [int(x) for x in f.readline().strip()]
    b = [int(x) for x in f.readline().strip()]
    a = [0 for i in range(255 - len(a))] + a
    b = [0 for i in range(255 - len(b))] + b
    for i in range(255):
        if b[i]:
            a[i] += 1
            while 2 in a:
                k = a.index(2)
                a[k] = 0
                a[k - 1] += 1
                if k == 253:
                    a[k + 1] += 1
                elif k < 253:
                    a[k + 2] += 1
                restore(a)
            restore(a)
    q.write(''.join(str(x) for x in a[a.index(1):]))
                
