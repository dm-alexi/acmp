with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n = int(f.readline())
    s = [int(x) for x in f.readline().split()]
    p = [str(i + 1) for i in range(n) if s[i] > 0] if sum(x for x in s if x > 0) >= -sum(x for x in s if x < 0) else [str(i + 1) for i in range(n) if s[i] < 0]
    q.write(str(len(p)) + "\n" + ' '.join(p))
