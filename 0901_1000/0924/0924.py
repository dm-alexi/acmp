with open("input.txt", "r") as f, open("output.txt", "w") as q:
    s = f.read().split('\n')
    q.write("No" if sum(s[i][j] == s[i + 1][j] and s[i][j] == s[i][j + 1] and s[i][j] == s[i + 1][j + 1] for j in range(3) for i in range(3)) else "Yes")
