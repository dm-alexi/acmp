with open("input.txt", "r") as f, open("output.txt", "w") as q:
    s, t = f.read().split()
    q.write("Yes" if s == "Home" or int(t) % 2 else "No")
    
           
        
