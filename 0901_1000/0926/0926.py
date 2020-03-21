with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n = int(f.readline())
    s = [f.readline().strip() for i in range(n)]
    k = sum(sum(l == 'C' for l in line) for line in s) / 2
    a = []
    for line in s:
        for l in line:
            a.append('1' if k else '2')
            if k and l == 'C':
                k -= 1
        a.append('\n')
    q.write(''.join(a))
