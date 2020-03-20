with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n = int(f.readline())
    s = [int(x) for x in f.read().split()]
    q.write(str(max(s[i - 2] + s[i - 1] + s[i] for i in range(n))))
