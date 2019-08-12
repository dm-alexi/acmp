with open("input.txt", "r") as f:
    with open("output.txt", "w") as q:
        a = f.read().split()
        q.write(str(int(a[0]) + int(a[1])))
