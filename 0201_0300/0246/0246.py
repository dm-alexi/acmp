with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n = int(f.readline())
    s = [int(x) for x in f.read().split()]
    q.write(str(sum(1 for i in range(1, n) if s[i] != s[i - 1] + 1)))
