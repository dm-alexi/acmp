def func(n):
    while not (n & 1):
        n >>= 1
    return 1 if n == 1 else func(n // 2) + func(n // 2 + 1)

with open("input.txt", "r") as f, open("output.txt", "w") as q:
    q.write(str(func(int(f.readline()))))
