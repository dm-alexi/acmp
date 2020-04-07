with open("input.txt", "r") as f, open("output.txt", "w") as q:
    s = [int(x) for x in f.read().split()]
    x, y = abs(s[0] - s[2]), abs(s[1] - s[3])
    q.write('1' if x == y else '2' if x % 2 == y % 2 else '0')
