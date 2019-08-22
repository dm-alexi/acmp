with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n = int(f.readline())
    p = [0] * 201
    for x in f.read().split():
        p[int(x) + 100] += 1
    for i in range(201):
        if p[i]:
            q.write(' '.join([str(i - 100)] * p[i]) + ' ')
