with open("input.txt", "r") as f, open("output.txt", "w") as q:
    s = "0000111162481397646455556666179368421919"
    a, b = (int(x) for x in f.read().split())
    q.write(s[a % 10 * 4 + b % 4])
