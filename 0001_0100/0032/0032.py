def fsort(a, rev):
    sign = 1
    if a[0] == '-':
        sign = -1
        rev = not rev
        a = a[1:]
    a.sort(reverse = rev)
    if a[0] == '0' and not rev and len(a) > 1:
        for i in range(1, len(a)):
            if a[i] != '0':
                a[0], a[i] = a[i], '0'
                break
    return sign * int("".join(a))
        
with open("input.txt", "r") as f, open("output.txt", "w") as q:
    a, b = map(list, f.read().split())
    q.write(str(fsort(a, True) - fsort(b, False)))
