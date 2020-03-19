with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n = int(f.readline())
    k = 0
    while n:
        n -= 1
        s = f.readline()
        if s[0] == s[3]:
            k += 1
    q.write(str(k))
