import re
with open("input.txt", "r") as f, open("output.txt", "w") as q:
    s = f.readline().strip()
    ans = "Error!"
    if s and "__" not in s and s[0] != '_' and s[-1] != '_' and s[0].islower() and (s.islower() or '_' not in s):
        if '_' in s:
            s = s.split('_')
            ans = s[0] + ''.join(l.capitalize() for l in s[1:])
        else:
            ans = '_'.join(t.lower() for t in filter(None, re.split("([A-Z][a-z]*)", s)))
    q.write(ans)
