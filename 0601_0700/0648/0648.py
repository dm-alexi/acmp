with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n = int(f.readline())
    s = [int(x) for x in f.readline().split()]
    s.sort()
    q.write(str(sum(s[n // 2:]) - sum(s[:n // 2])))
