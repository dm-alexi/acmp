with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n = int(f.readline())
    s = [int(x) for x in f.read().split()]
    k = next((i for i in range(n) if s[i] <= 437), -1)
    q.write("No crash" if k < 0 else "Crash {}".format(k + 1))
