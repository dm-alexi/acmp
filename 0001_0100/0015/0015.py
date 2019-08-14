with open("input.txt", "r") as f, open("output.txt", "w") as q:
    a = 0
    for x in f.read().split()[1:]:
        if x == '1':
            a += 1
    q.write(str(a // 2))
