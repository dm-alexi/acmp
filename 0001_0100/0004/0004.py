with open("input.txt", "r") as f:
    with open("output.txt", "w") as q:
        a = int(f.read())
        q.write(str(a) + "9" + str(9 - a))
