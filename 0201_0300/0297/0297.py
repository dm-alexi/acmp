with open("input.txt", "r") as f, open("output.txt", "w") as q:
    q.write(str(sum(1 if x in "069" else 2 if x == '8' else 0 for x in f.readline().strip())))
