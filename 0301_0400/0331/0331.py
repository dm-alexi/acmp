with open("input.txt", "r") as f, open("output.txt", "w") as q:
    h, m = (int(x) for x in f.readline().strip().split(':'))
    a, b = (int(x) for x in f.readline().split())
    h, m = ((h + a + 1) % 24, (m + b) % 60) if m + b >= 60 else ((h + a) % 24, m + b)
    q.write(f"{h:02d}:{m:02d}")
