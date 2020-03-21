with open("input.txt", "r") as f, open("output.txt", "w") as q:
    s = ["GCV", "VGC", "CVG"]
    q.write(s[int(f.readline()) % 3])
