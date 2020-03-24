with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n, m = (int(x) for x in f.readline().split())
    q.write((str(n // m) + ' ') * (m - n % m) + (str(n // m + 1) + ' ') * (n % m))
