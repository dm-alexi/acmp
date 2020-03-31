with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n = int(f.readline())
    d = dict()
    for i in range(n):
        s = f.readline()
        d[s[0]] = s[1]
    s = [x for x in f.readline().strip()]
    i = 0 
    while i < len(s) - 1:
        while i < len(s) - 1 and i >= 0 and s[i] in d and s[i + 1] == d[s[i]]:
            del s[i:i + 2]
            i -= 1
        i += 1
    q.write(''.join(s))
    
