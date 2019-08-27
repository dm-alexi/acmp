with open("input.txt", "r") as f, open("output.txt", "w") as q:
    q.write(str(45 ** int(f.read())))
    
