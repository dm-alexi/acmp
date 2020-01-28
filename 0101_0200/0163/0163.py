with open("input.txt", "r") as f, open("output.txt", "w") as q:
    s = f.readline()
    if s[4] == 'x':
        n = int(s[0]) + int(s[2]) if s[1] == '+' else int(s[0]) - int(s[2])
    elif s[0] == 'x':
        n = int(s[4]) - int(s[2]) if s[1] == '+' else int(s[4]) + int(s[2])
    else:
        n = int(s[4]) - int(s[0]) if s[1] == '+' else int(s[0]) - int(s[4])
    q.write(str(n))
