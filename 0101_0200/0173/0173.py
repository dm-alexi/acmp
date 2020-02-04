def pal(s):
    return s == s[::-1]

def conv(n, t):
    alphabet = "0123456789ABCDEFGHIJKLMNOPQRTSUVWXYZ"
    s = []
    while n:
        s.append(alphabet[n % t])
        n //= t
    return "".join(s)

with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n = int(f.read().strip())
    s = []
    for i in range(2, 37):
        if pal(conv(n, i)):
            s.append(str(i))
    q.write("none" if len(s) == 0 else "unique\n" if len(s) == 1 else "multiple\n")
    q.write(" ".join(s))

