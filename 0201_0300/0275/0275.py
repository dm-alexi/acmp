with open("input.txt", "r") as f, open("output.txt", "w") as q:
    for i in range(int(f.readline())):
        q.write("No\n" if int(f.readline(), base = 2) % 7 else "Yes\n")
