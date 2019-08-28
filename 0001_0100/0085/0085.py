with open("input.txt", "r") as f, open("output.txt", "w") as q:
    a, b = (int(x) for x in f.read().split())
    while b:
        a, b = b, a % b
    q.write("1" * a)
