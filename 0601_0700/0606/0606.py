with open("input.txt", "r") as f, open("output.txt", "w") as q:
    a, b, c = (int(x) for x in f.readline().split())
    q.write("YES" if a + b > c and a + c > b and b + c > a else "NO")
