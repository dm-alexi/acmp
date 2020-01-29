with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n = f.readline().strip()
    s = ""
    for i in range(1, 10001):
        s += str(i)
    q.write(str(s.find(n) + 1))
