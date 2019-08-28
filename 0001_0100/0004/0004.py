with open("input.txt", "r") as f, open("output.txt", "w") as q:
    a = int(f.read())
    q.write("{}9{}".format(a, 9 - a))
