with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n = int(f.readline())
    i = 2
    k = 1
    while i <= n:
        k *= i
        i += 1
    q.write(str(k))
