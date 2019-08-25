with open("input.txt", "r") as f, open("output.txt", "w") as q:
    s = f.read().strip()
    q.write("BLACK" if s[0] in "ACEG" and s[1] in "1357" or s[0] in "BDFH" and s[1] in "2468" else "WHITE")
        
    
           
        
