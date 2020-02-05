import re
with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n = int(f.readline())
    day = (0, 14880, 28320, 43200, 57600, 72480, 86880, 101760, 116640, 131040, 145920, 160320)
    p = []    
    for i in range(n):
        s = [int(x) for x in re.split('\.?[ :\.]', f.readline().strip())]
        p.append(day[s[1] - 1] + s[0] * 480 + s[2] * 60 + s[3])
    p.sort()
    d = sum(-p[i] if i % 2 == 0 else p[i] + 1 for i in range(n))
    q.write("{:d}:{:02d}".format(d // 60, d % 60))
