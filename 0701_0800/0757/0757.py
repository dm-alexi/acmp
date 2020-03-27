with open("input.txt", "r") as f, open("output.txt", "w") as q:
    a, b, c = (int(x) for x in f.readline().split())
    q.write(str(min(a // 2, b // 6, c))) 
