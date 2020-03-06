import textwrap
with open("input.txt", "r") as f, open("output.txt", "w") as q:
    s = f.readline().strip()
    n = 0
    i = 0
    a = ""
    for x in s:
        if x in "0123456789":
            n = n * 10 + "0123456789".index(x)
        elif n == 0:
            a += x
        else:
            a += x * n
            n = 0
    q.write('\n'.join(textwrap.wrap(a, 40)))
                
