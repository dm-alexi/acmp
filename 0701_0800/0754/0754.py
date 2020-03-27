with open("input.txt", "r") as f, open("output.txt", "w") as q:
    s = [int(x) for x in f.readline().split()]
    q.write("Error" if max(s) > 727 or min(s) < 94 else str(max(s)))
