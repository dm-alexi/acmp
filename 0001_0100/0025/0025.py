with open("input.txt", "r") as f, open("output.txt", "w") as q:
    a, b = map(int, f.read().split())
    q.write('>' if a > b else '<' if a < b else '=')
