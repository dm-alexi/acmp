with open("input.txt", "r") as f, open("output.txt", "w") as q:
    s, m = (int(x) for x in f.read().split())
    y = int((s + (s * s - 4 * m) ** 0.5) / 2)
    x = s - y
    if x > y:
        x, y = y, x
    q.write('{} {}'.format(x, y))
        
    
           
        
