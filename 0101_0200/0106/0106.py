with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n = int(f.readline())
    s = sum(1 for x in f.read().split() if x == "1")
    q.write(str(min(s, n - s)))
