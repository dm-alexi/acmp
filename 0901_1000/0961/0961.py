with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n, m = (int(x) for x in f.readline().split())
    s1 = [f.readline().strip() for i in range(n)]
    f.readline()
    s2 = [f.readline().strip() for i in range(n)]
    a = [s1[i][j] for j in range(m) for i in range(n) if s1[i][j] != '.' and s1[i][j] != s2[i][j]]
    a.sort(key = lambda x: ord(x) - ord('a') - 26 if x.islower() else ord(x) - ord('A'))
    q.write(str(len(a)) + '\n' + ''.join(a) if len(a) > 0 else "0")
