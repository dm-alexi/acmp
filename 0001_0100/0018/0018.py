with open("input.txt", "r") as f, open("output.txt", "w") as q:
    k = 1
    for i in range(2, int(f.read()) + 1):
        k *= i
    q.write(str(k))
