with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n = int(f.readline())
    songs = dict()
    for i in range(n):
        s = f.readline().split()
        songs[s[0]] = [i, int(s[1]), 0]
    m, k = (int(x) for x in f.readline().split())
    playlist = [f.readline().strip() for i in range(m)]
    stops = [int(x) for x in f.readline().split()]
    l, j = 0, 0
    for name in playlist:
        if j == k or l + songs[name][1] <= stops[j]:
            songs[name][2] += 1
            l += songs[name][1]
        else:
            songs[name][2] -= 1
            l = stops[j]
            j += 1
    q.write(" ".join(str(x[2]) for x in sorted(list(songs.values()))))
