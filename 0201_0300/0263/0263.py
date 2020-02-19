with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n, i, j = (int(x) for x in f.readline().split())
    if i > j:
        i, j = j, i
    q.write(str(min(j - i, n - j + i) - 1))
