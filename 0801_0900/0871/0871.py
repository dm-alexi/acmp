with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n, m = (int(x) for x in f.readline().split())
    s = [set() for i in range(n)]
    for i in range(m):
        a, b = (int(x) - 1 for x in f.readline().split())
        s[a].add(b)
        s[b].add(a)
    finished = False   
    while not finished:
        finished = True
        for i in range(n):
            if len(s[i]) == 1:
                finished = False
                s[s[i].pop()].remove(i)
    q.write("YES" if True in (len(x) > 0 for x in s) else "NO")
