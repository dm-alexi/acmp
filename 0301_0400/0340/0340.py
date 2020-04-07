with open("input.txt", "r") as f, open("output.txt", "w") as q:
    a = sorted(int(x) for x in f.readline().split())
    b = sorted(int(x) for x in f.readline().split())
    q.write("Boxes are equal" if a == b else \
        "The first box is larger than the second one" if all(a[i] >= b[i] for i in range(3)) else \
        "The first box is smaller than the second one" if all(a[i] <= b[i] for i in range(3)) else \
        "Boxes are incomparable")
