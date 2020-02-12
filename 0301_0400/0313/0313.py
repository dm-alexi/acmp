with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n = int(f.readline())
    m = [0 for i in range(101)]
    k = 0
    s = [int(x) for x in f.readline().split()]
    for i in range(1, n + 1):
        if m[s[i - 1]] and i - m[s[i - 1]] > k:
            k = i - m [s[i - 1]]
        m[s[i - 1]] = i
    q.write(str(k))
