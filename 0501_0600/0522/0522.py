with open("input.txt", "r") as f, open("output.txt", "w") as q:
    f.readline()
    a = set(f.readline().split())
    b = set(f.readline().split())
    q.write('1' if a == b else '0')
        
