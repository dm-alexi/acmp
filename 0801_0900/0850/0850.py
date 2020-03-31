with open("input.txt", "r") as f, open("output.txt", "w") as q:
    s = sorted([int(x) for x in f.readline().split()])
    q.write(f"{(s[1] + 1) // 2} {s[0]}")
    
