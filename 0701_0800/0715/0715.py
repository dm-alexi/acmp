with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n, m = (int(x) for x in f.readline().split())
    s1 = ''.join(f.readline().strip() for i in range(n))
    f.readline()
    s2 = ''.join(f.readline().strip() for i in range(n))
    q.write(str(sum(s1[i] == s2[i] for i in range(n * m))))
