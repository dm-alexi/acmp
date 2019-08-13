with open("input.txt", "r") as f, open("output.txt", "w") as q:
    k, n = (int(x) for x in f.read().split())
    a = [1, 1]
    for i in range(2, n + 1):
        a.append(a[-1] * 2)
        if (i > k):
            a[i] -= a[i - k - 1]
    q.write(str(a[n]))
