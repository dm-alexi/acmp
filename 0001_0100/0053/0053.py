with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n, m = map(int, f.read().split())
    r = (n // 2 - n // 10 - n // 6 + n // 30) * (m - m // 5 - m // 3 + m // 15) +\
        (n - n // 2 - n // 3 - n // 5 + n // 10 + n // 6 + n // 15 - n // 30) *\
        (m // 2 - m // 10 - m // 6 + m // 30)
    g = (n // 3 - n // 15) * (m - m // 5) + (n - n // 3 - n // 5 + n // 15) *\
        (m // 3 - m // 15)
    b = n // 5 * m + m // 5 * n - (n // 5) * (m // 5)
    q.write("RED : {}\nGREEN : {}\nBLUE : {}\nBLACK : {}".format(r, g, b, n * m - r - g - b))
