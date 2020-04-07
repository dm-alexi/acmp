def leap(n):
    return 1 if (n % 4 == 0 and n % 100) or (n % 400 == 0) else 0

with open("input.txt", "r") as f, open("output.txt", "w") as q:
    m = (31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31)
    d, t = [int(x) for x in f.readline().split('.')], [int(x) for x in f.readline().split('.')]
    d[0] += 1 if leap(d[2]) and d[1] > 2 else 0
    t[0] += 1 if leap(t[2]) and t[1] > 2 else 0
    d[0] += sum(m[:d[1] - 1])
    t[0] += sum(m[:t[1] - 1])
    t[0] += sum(365 + leap(i) for i in range(d[2], t[2]))
    q.write(str(t[0] - d[0] + 1))
