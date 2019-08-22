with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n = int(f.read())
    s = "2.7182818284590452353602875"
    if n < 25:
        s = "3" if n == 0 else s[:n + 1] + str(int(s[n + 1]) + 1) if s[n + 2] >= '5' else s[:n + 2]
    q.write(s)
