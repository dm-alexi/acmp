from decimal import Decimal
with open("input.txt", "r") as f, open("output.txt", "w") as q:
    a, b = (Decimal(x) for x in f.readlines())
    q.write('<' if a < b else '>' if a > b else '=')
