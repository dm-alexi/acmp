import re
with open("input.txt", "r") as f, open("output.txt", "w") as q:
    s = [x for x in re.split("([A-Z][a-z]?)", f.readline().strip()) if x]
    r = not (s[0].isdigit() or '1' in s or any(x[0] == '0' for x in s))
    if r:
        s = [x for x in s if x.isalpha()]
        for i in range(1, len(s)):
            if s[i] == s[i - 1]:
                r = False
                break
    q.write("YES" if r else "NO")
