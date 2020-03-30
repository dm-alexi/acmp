with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n = int(f.readline())
    q.write(str(1 + sum(int(x) for x in f.readline().split()) - n))
