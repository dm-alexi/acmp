with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n, s = f.read().split()
    n = int(n)
    q.write(s[:n - 1] + s[n:])
