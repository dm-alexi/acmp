with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n, k = int(f.read()), 0
    while n:
        k = (k << 1) | (n & 1)
        n >>= 1
    q.write(str(k))
