with open("input.txt", "r") as f, open("output.txt", "w") as q:
    name = f.readline().split()[1]
    s = f.readline().strip()[10:]
    d = False
    while s != name + " signed off":
        if s[-1] == '.':
            s = s[:-1] + ','
        elif s[-1] not in '!?':
            s += ','
        q.write(f'"{s}" --- skazal {name if d else "Fedya"}.\n')
        d = not d
        s = f.readline().strip()[10:]
