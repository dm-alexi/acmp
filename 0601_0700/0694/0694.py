with open("input.txt", "r") as f, open("output.txt", "w") as q:
    f.readline()
    s = [int(x) for x in f.read().split()]
    q.write("NO" if max(s[::2]) > min(s[1::2]) else "YES")
