with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n = int(f.read())
    q.write("Error" if n < 1 or n > 12 else "Winter" if n < 3 or n == 12 else "Spring" if n < 6 else "Summer" if n < 9 else "Autumn")
