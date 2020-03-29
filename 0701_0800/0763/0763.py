with open("input.txt", "r") as f, open("output.txt", "w") as q:
    a, b = f.readline().split()
    q.write("0" if (a, b) == ("1", "1") else "2" if a == b else "1")
