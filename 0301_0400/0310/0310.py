with open("input.txt", "r") as f, open("output.txt", "w") as q:
    for s in f.readlines()[1:]:
        x, y, a = (int(x) for x in s.split())
        q.write('1' if a < 3 or x % a + y % a == 2 else '0')
