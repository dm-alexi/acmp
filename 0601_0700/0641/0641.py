with open("input.txt", "r") as f, open("output.txt", "w") as q:
    s = [x for x in f.readline().strip()]
    n = len(s)
    i = 0
    while i < n - 1 and s[i] >= s[i + 1]:
        i += 1
    del s[i]
    i = i - 1 if i else 0
    while i < n - 2 and s[i] >= s[i + 1]:
        i += 1
    del s[i]
    q.write(''.join(s))
    
    
