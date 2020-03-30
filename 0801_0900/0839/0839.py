with open("input.txt", "r") as f, open("output.txt", "w") as q:
    q.write("NO" if '0' in f.readline() else "YES")
