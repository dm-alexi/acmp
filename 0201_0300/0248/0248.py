import re
with open("input.txt", "r") as f, open("output.txt", "w") as q:
    articles = {"a", "A", "an", "An", "the", "The", ""}
    s = list(filter(lambda x: x not in articles, f.readline().split()))
    for j in range(len(s)):
        tmp = list(filter(lambda x: x not in articles, re.split("(\W+)", s[j])))
        for i in range(len(tmp)):
            up = tmp[i][0].isupper()
            tmp[i] = re.sub(r"(\w)\1+", r"\g<1>", tmp[i].lower().replace("ce", "se").replace("ci", "si").replace("ck", "k").replace("c", "k").replace("ee", "i").replace("oo", "u"))
            if tmp[i][-1] == 'e' and tmp[i] != 'e':
                tmp[i] = tmp[i][:-1]
            if up:
                tmp[i] = tmp[i].capitalize()
        s[j] = ''.join(tmp)
    q.write(' '.join(s))
