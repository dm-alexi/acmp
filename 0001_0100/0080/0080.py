import re
with open("input.txt", "r") as f, open("output.txt", "w") as q:
    s = f.read()
    ans = "ERROR"
    if re.fullmatch("[-]?\d+[*+/-]{1}[-]?\d+=[-]?\d+[\n]?", s):
        s = re.split("([*+/-])([-]?\d+)(=)", s.strip())
        a, b, c = int(s[0]), int(s[2]), int(s[4])
        a = a + b if s[1] == '+' else a - b if s[1] == '-' else a * b if s[1] == '*' else\
            a // b if s[1] =='/' and b and a % b == 0 else c + 1
        ans = "YES" if a == c else "NO"
    q.write(ans)
