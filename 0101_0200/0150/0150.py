def dfs(m, n, r, d):
    r[d] = True
    return sum(dfs(m, n, r, i) if m[d][i] and not r[i] else 0 for i  in range(n)) + 1

with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n, s = (int(x) for x in f.readline().split())
    m = [[x == "1" for x in f.readline().split()] for i in range(n)]
    r = [False for i in range(n)]
    q.write(str(dfs(m, n, r, s - 1) - 1))
