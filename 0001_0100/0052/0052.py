with open("input.txt", "r") as f, open("output.txt", "w") as q:
    s = [int(x) for x in f.read().strip()]
    q.write("YES" if sum(s[:3]) == sum(s[3:]) else "NO")

        
