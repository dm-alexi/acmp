with open("input.txt", "r") as f, open("output.txt", "w") as q:
    h, m = (int(x) for x in f.read().split(':'))
    if m >= h % 10 * 10 + h // 10:
        h = (h + 1) % 24
    if h % 10 > 5:
        h += 10 - h % 10
    q.write(f"{h:02d}:{h % 10 * 10 + h // 10:02d}")
