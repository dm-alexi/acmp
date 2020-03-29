with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n, m, i, j, c = (int(x) for x in f.readline().split())
    q.write("equal" if not (m % 2 and n % 2) else "white" if ((i - 1) * n + j) % 2 == c else "black")
