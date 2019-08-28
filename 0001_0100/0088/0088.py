with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n = int(f.readline())
    r = 1
    t = []
    for i in range(n * n):
        t.append([int(x) for x in f.readline().split()])
    for i in range(n * n):
        s = [set(t[i]), set(), set()]
        for j in range(n * n):
            s[1].add(t[j][i])
            s[2].add(t[i // n * n + j // n][i % n * n + j % n])
        for x in s:
            if len(x) < n * n or max(x) != n * n or min(x) != 1:
                r = 0
                break
        if not r:
            break
    q.write("Correct" if r else "Incorrect")
        
