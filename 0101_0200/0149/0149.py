with open("input.txt", "r") as f, open("output.txt", "w") as q:
    q.write(' '.join(reversed(f.read().split()[1:])))
