with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n = int(f.read()) // 6
    q.write("{} {} {}".format(n, n * 4, n))
