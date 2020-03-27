from math import ceil
with open("input.txt", "r") as f, open("output.txt", "w") as q:
    l, w, h = (int(x) for x in f.readline().split())
    q.write(str(ceil(2 * h * (l + w) / 16)))
