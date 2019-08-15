with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n = int(f.readline())
    p = f.readline().split()
    i = 1
    while i < n:
        if (n - 1) % i == 0 and p[i] == p[0]:
            j = i
            while j < n:
                if p[j] != p[j % i]:
                    break
                j += 1
            if j == n:
                break
        i += 1
    q.write(str(i))
