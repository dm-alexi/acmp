with open("input.txt", "r") as f, open("output.txt", "w") as q:
    for i in range(int(f.readline())):
        s = f.readline().strip()
        n = len(s)
        q.write("YES\n" if n % 3 == 0 and s == '0' * (n // 3) + '1' * (n // 3) + '2' * (n // 3) else "NO\n")
