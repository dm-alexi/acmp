with open("input.txt", "r") as f, open("output.txt", "w") as q:
    a, b = f.readline().strip(), f.readline().strip()
    q.write("YES" if {c:a.count(c) for c in "ABCDEFGHIJKLMNOPQRSTUVWXYZ"} == {c:b.count(c) for c in "ABCDEFGHIJKLMNOPQRSTUVWXYZ"} else "NO")
