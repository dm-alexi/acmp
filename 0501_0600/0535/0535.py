def prolong(s):
    return "0" * (24 - len(s)) + s

def wsum(a, b):
    return "".join(str(int(a[i]) + int(b[i])) for i in range(24))[-24:]

with open("input.txt", "r") as f, open("output.txt", "w") as q:
    a, b, c = (prolong(x) for x in f.read().split())
    s = list({int(wsum(c, wsum(a, b))), int(wsum(b, wsum(a, c))), int(wsum(a, wsum(b, c)))})
    s.sort()
    q.write("NO\n" if len(s) == 1 else "YES\n")
    q.write("\n".join(str(x) for x in s))
