import re

with open("input.txt", "r") as f, open("output.txt", "w") as q:
    m = 1441
    for i in range(int(f.readline())):
        t = re.split('(".+") (\d\d):(\d\d) (\d\d):', f.readline().strip())[1:]
        a = (int(t[3]) - int(t[1])) * 60 + int(t[4]) - int(t[2])
        if a <= 0:
            a += 1440
        if a < m:
            m, s = a, t[0]
    q.write("The fastest train is {}.\nIts speed is {} km/h, approximately.".format(s, int(650 * 60 / m + 0.5)))
        
