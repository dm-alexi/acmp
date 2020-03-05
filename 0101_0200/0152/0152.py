def dfs(p, num):
    if p[num][0] == 2:
        return 0
    if p[num][0] == 1:
        return 1
    p[num][0] = 1
    for x in p[num][1]:
        if dfs(p, x) == 1:
            return 1
    p[num][0] = 2
    return 0

with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n, m = (int(x) for x in f.readline().split())
    r = "Yes"
    p = {i + 1:[0, []] for i in range(n)}
    for i in range(m):
        a, b = (int(x) for x in f.readline().split())
        p[a][1].append(b)
    for i in range(n):
        if dfs(p, i + 1) == 1:
            r = "No"
            break
    q.write(r)
        
