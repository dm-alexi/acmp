with open("input.txt", "r") as f, open("output.txt", "w") as q:
    s = f.read().strip()
    i = len(s) - 1
    while s[i] == "0":
        i -= 1
    q.write("1" + s[i + 1:])
