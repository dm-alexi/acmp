with open("input.txt", "r") as f, open("output.txt", "w") as q:
    k, m = (int(x) for x in f.readline().split())
    q.write(str(int(f.read(), base = k) % m))
