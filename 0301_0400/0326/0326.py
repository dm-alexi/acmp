from collections import Counter
with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n = int(f.readline())
    m = [int(x) for x in f.read().split()]
    a, b = 0, 0
    for x, y in Counter(m).items():
        if y > b or (y == b and x < a):
            a, b = x, y
    q.write(" ".join(str(x) for x in m if x != a))
    q.write(" ")
    q.write(" ".join(str(a) for i in range(b)))
