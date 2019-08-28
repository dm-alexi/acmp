with open("input.txt", "r") as f, open("output.txt", "w") as q:
    s = f.read().strip()
    l = "ABCDEFGH"
    n = "12345678"
    q.write("ERROR" if not (len(s) == 5 and s[0] in l and s[3] in l and s[1] in n and s[4] in n and s[2]=='-')
        else "YES" if abs((ord(s[0]) - ord(s[3])) * (int(s[1]) - int(s[4]))) == 2 else "NO")
