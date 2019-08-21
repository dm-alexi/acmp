with open("input.txt", "r") as f, open("output.txt", "w") as q:
    k = int(f.readline())
    while k:
        k -= 1
        n, m = map(int, f.readline().split())
        q.write(str(19 * m + (n + 239) * (n + 366) // 2) + '\n')
