with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n, s = (int(x) for x in f.readline().split())
    p = [int(x) for x in f.readline().split()]
    p.sort()
    k, a = 0, 0
    for x in p:
        if k + x > s:
            break
        k += x
        a += 1
    q.write(str(a))
        
