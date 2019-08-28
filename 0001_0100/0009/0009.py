with open("input.txt", "r") as f, open("output.txt", "w") as q:
    s = [int(x) for x in f.read().split()[1:]]
    t = sum((x for x in s if x > 0))
    smin, smax = s.index(min(s)), s.index(max(s))
    m = 1
    for x in s[min(smin, smax) + 1 : max(smin, smax)]:
        m *= x
    q.write('{} {}'.format(t, m))
