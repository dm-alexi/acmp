import math

with open("input.txt", "r") as f, open("output.txt", "w") as q:
    x1, y1, x2, y2, r, s = map(int, f.read().split())
    k = ((x1 - x2) ** 2 + (y1 - y2) ** 2) ** 0.5 / 2
    a = 2 * math.acos((k / r) % 1)
    sn = 2 * math.pi * r * r if k >= r else r * r * (2 * math.pi - a + math.sin(a))
    q.write("YES" if sn > s else "NO")
