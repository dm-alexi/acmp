with open("input.txt", "r") as f, open("output.txt", "w") as q:
    s = f.read().strip()
    d = " abcdefghijklmnopqrstuvwxyz"
    q.write("".join(d[(int(s[i], 27) - (i + 1) % 27 + 27) % 27] for i in range(len(s))))
