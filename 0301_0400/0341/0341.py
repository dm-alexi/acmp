with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n = int(f.read())
    if n < 12:
        s = str(n - 1)
    elif n == 12:
        s = '22'
    elif n < 20:
        s = str(30 + (n - 13) * 10 + (n + 1) % 2)
    elif n == 20:
        s = '111'
    else:
        n -= 21
        c = '1' if n % 2 else '0'
        s = [c for i in range(n // 8 + 3)]
        s[0] = str(n % 8 + 2)
        s = "".join(s)
    q.write(s)
