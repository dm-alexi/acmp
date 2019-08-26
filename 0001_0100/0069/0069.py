import math
with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n, a = (int(x) for x in f.read().split())
    q.write("YES" if a * (1 - math.cos(math.pi / n)) / ( 2 * math.sin(math.pi / n)) < 1 else "NO")
    
           
        
