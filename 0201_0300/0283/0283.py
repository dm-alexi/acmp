import re
with open("input.txt", "r") as f, open("output.txt", "w") as q:
    s = list(filter(None, re.split("([A-Z][a-z]*)", f.readline().strip())))
    ans = "Yes"
    for t in s:
        if len(t) < 2 or len(t) > 4 or t[0].islower() or not t[1:].islower():
            ans = "No"
            break
    q.write(ans)
