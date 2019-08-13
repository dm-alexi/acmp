with open("input.txt", "r") as f, open("output.txt", "w") as q:
    a = int(f.read()) // 10
    if a > 0:
        q.write(str(a * (a + 1)))
    q.write("25")
