with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n, k = (int(x) for x in f.readline().split())
    q.write(f"{n * n *k}")
