with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n = int(f.readline())
    a = k = -1
    for i in range(n):
        t, s = (int(x) for x in f.readline().split())
        if s and t > k:
            k = t
            a = i + 1
    q.write(str(a))
