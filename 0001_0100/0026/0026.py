with open("input.txt", "r") as f, open("output.txt", "w") as q:
    x1, y1, r1 = map(int, f.readline().split())
    x2, y2, r2 = map(int, f.readline().split())
    m = (x1 - x2)**2 + (y1 - y2)**2
    q.write("NO" if m > (r1 + r2)**2 or m < (r1 - r2)**2 else "YES")
