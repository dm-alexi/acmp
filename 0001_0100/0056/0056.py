with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n = int(f.readline())
    friends = [f.readline().strip() for i in range(n)]
    friends.sort()
    mfriends, afriends = [], []
    m = int(f.readline())
    for i in range(m):
        s = f.readline().strip()
        if s in friends:
            mfriends.append(s)
        else:
            afriends.append(s)
    mfriends.sort()
    afriends.sort()
    q.write("\n".join(("Friends: " + ", ".join(friends), "Mutual Friends: " + ", ".join(mfriends),
        "Also Friend of: " + ", ".join(afriends))))
        
