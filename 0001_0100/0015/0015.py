with open("input.txt", "r") as f, open("output.txt", "w") as q:
    q.write(str(sum(1 for x in f.read().split()[1:] if x == '1') // 2))
