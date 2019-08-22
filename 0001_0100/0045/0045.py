with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n = int(f.read())
    if n > 1:
        a = [0] * 10
        for i in range(9, 1, -1):
            while n % i == 0:
                n //= i
                a[i] += 1
        s = "".join((str(i) * a[i]) for i in range(2, 10)) if n == 1 else "-1"
    else:
        s = "1" if n else "10"
    q.write(s)
