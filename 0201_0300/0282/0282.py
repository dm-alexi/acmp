with open("input.txt", "r") as f, open("output.txt", "w") as q:
    w, h = (int(x) for x in f.read().split())
    q.write(str(w * (w + 1) * h * (h + 1) // 4))
