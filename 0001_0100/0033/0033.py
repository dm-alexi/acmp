with open("input.txt", "r") as f, open("output.txt", "w") as q:
    q.write(' '.join([str(int(x) - 1) for x in f.read().split()[::-1]]))
