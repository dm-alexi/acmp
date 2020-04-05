with open("input.txt", "r") as f, open("output.txt", "w") as q:
    q.write(str(int(f.readline()) * int(f.readline())))
