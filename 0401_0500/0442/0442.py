import re
with open("input.txt", "r") as f, open("output.txt", "w") as q:
    s = [x.strip() for x in re.split("(<[^>]*>)", f.read().strip()) if x and not x.isspace()]
    d = [0 for i in range(50)]
    fnt = [10]
    for x in s:
        if x[0] != '<':
            d[fnt[-1] - 1] += sum(not i.isspace() for i in x)
        elif x[:12] == '<font size="':
            if x[12] in "+-":
                fnt.append(fnt[-1] + int(x[12:-2]))
            else:
                fnt.append(int(x[12:-2]))
        elif x == '</font>':
            fnt.pop()
    q.write("\n".join(f"{i + 1} {d[i]}" for i in range(50) if d[i]))
    
    
