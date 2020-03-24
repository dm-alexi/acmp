with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n, m = (int(x) for x in f.readline().split())
    l = lambda x: x.index('B') - x.rindex('A') - 1
    q.write(str(min(l(f.readline()) for i in range(n))))
