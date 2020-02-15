with open("input.txt", "r") as f, open("output.txt", "w") as q:
    p = sorted([int(x) for x in f.readline().split()])
    s = 'Nothing'
    if p[0] == p[4]:
        s = "Impossible"
    elif p[0] == p[3] or p[1] == p[4]:
        s = "Four of a Kind"
    elif (p[0] == p[2] and p[3] == p[4]) or (p[0] == p[1] and p[2] == p[4]):
        s = "Full House"
    elif p[0] + 1 == p[1] and p[1] + 1 == p[2] and p[2] + 1 == p[3] and p[3] + 1 == p[4]:
        s = "Straight"
    elif p[0] == p[2] or p[1] == p[3] or p[2] == p[4]:
        s = "Three of a Kind"
    elif (p[0] == p[1] and (p[2] == p[3] or p[3] == p[4])) or (p[1] == p[2] and p[3] == p[4]):
        s = "Two Pairs"
    elif p[0] == p[1] or p[1] == p[2] or p[2] == p[3] or p[3] == p[4]:
        s = "One Pair"
    q.write(s)
