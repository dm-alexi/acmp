with open("input.txt", "r") as f, open("output.txt", "w") as q:
    s = [int(x) for x in f.readline().split()]
    a, b = sorted(s[:3]), sorted(s[3:])
    q.write(str(sum(a[i] * b[i] for i in range(3))))
