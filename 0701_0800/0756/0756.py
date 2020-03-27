with open("input.txt", "r") as f, open("output.txt", "w") as q:
    a, b = (int(x) for x in f.readline().split())
    q.write(str((a - 1) * (b - 1))) 
