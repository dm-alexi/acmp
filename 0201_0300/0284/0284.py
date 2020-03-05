with open("input.txt", "r") as f, open("output.txt", "w") as q:
    f.readline()
    p = f.readline().split()
    n = int(f.readline())
    for i in range(n):
        k, l = (int(x) for x in f.readline().split())
        q.write(' '.join(p[k - 1:l]) + '\n')
