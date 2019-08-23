with open("input.txt", "r") as f, open("output.txt", "w") as q:
    s = f.readline().strip()
    t = f.readline().strip()
    d = {str(a) : {a} for a in range(0, 10)}
    d.update({x : {i, i + 1, i + 2, i + 3} for i, x in enumerate("abcdefg")})
    d['?'] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}
    k = 1
    for i in range(len(s)):
        k *= len(d[s[i]] & d[t[i]])
    q.write(str(k))
