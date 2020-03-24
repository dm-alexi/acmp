with open("input.txt", "r") as f, open("output.txt", "w") as q:
    s = f.readline().strip()
    t = f.readline().strip()
    a = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    i = 0
    if not t in s:
        while i < 25:
            t = ''.join(a[(a.index(x) + 1) % 26] for x in t)
            if t in s:
                s = ''.join(a[(a.index(x) + 25 - i) % 26] for x in s)
                break
            i += 1
    q.write("IMPOSSIBLE" if i == 25 else s)
