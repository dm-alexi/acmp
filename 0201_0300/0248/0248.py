import re
with open("input.txt", "r") as f, open("output.txt", "w") as q:
    s = f.readline().split()
    articles = {"a", "A", "an", "An", "the", "The", ""}
    for t in articles:
        while t in s:
            s.remove(t)
    for j in range(len(s)):
        tmp = re.split("(\W+)", s[j])
        for t in articles:
            while t in tmp:
                tmp.remove(t)
        for i in range(len(tmp)):
            up = tmp[i][0].isupper()
            tmp[i] = re.sub(r"(\w)\1+", r"\g<1>", tmp[i].lower().replace("ce", "se").replace("ci", "si").replace("ck", "k").replace("c", "k").replace("ee", "i").replace("oo", "u"))
            if tmp[i][-1] == 'e' and tmp[i] != 'e':
                tmp[i] = tmp[i][:-1]
            if up:
                tmp[i] = tmp[i].capitalize()
        s[j] = ''.join(tmp)
    q.write(' '.join(s))
