with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n, m = (int(x) for x in f.readline().split())
    ymax = xmax = 0
    ymin, xmin = n, m
    for i in range(n):
        s = f.readline()
        if '*' in s:
            if i < ymin:
                ymin = i
            ymax = i
            if s.index('*') < xmin:
                xmin = s.index('*')
            if s.rindex('*') > xmax:
                xmax = s.rindex('*')
    a = "." * m + "\n"
    b = "." * xmin + "*" * (xmax + 1 - xmin) + "." * (m - xmax - 1) + "\n"
    for i in range(n):
        q.write(a if i < ymin or i > ymax else b)
                
