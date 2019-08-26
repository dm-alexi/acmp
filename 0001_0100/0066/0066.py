with open("input.txt", "r") as f, open("output.txt", "w") as q:
    s = "qwertyuiopasdfghjklzxcvbnmq"
    q.write(s[s.index(f.read().strip()) + 1])
