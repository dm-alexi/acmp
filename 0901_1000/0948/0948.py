from math import ceil
with open("input.txt", "r") as f, open("output.txt", "w") as q:
    k, n = (int(x) for x in f.read().split())
    q.write(f"{ceil(n / k)} {n % k if n % k else k}")
