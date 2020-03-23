with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n = int(f.readline())
    p = (int(x) for x in f.readline().split())
    k = int(f.readline())
    q.write(str(sum(min(l, k) for l in p)))
