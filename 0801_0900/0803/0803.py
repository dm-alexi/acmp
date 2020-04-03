with open("input.txt", "r") as f, open("output.txt", "w") as q:
    a, b, k = (int(x) for x in f.readline().split())
    for i in range(k):
        a = a % b * 10
    q.write(str(a // b))
