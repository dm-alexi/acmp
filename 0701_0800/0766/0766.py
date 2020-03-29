with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n, m, k = (int(x) for x in f.readline().split())
    q.write("YES" if n * m >= k else "NO")
