def fib(n):
    a = b = 1
    while b <= n:
        yield b
        a, b = b, a + b

with open("input.txt", "r") as f, open("output.txt", "w") as q:
    s = f.readline().strip()
    q.write(''.join(s[i - 1] for i in fib(len(s))))
