with open("input.txt", "r") as f, open("output.txt", "w") as q:
    m = [[1 if s[i] == 'X' else -1 if s[i] == 'O' else 0 for i in range(3)] for s in f.readlines()]
    p = [sum(m[0]), sum(m[1]), sum(m[2]), m[0][0] + m[1][0] + m[2][0], m[0][1] + m[1][1] + m[2][1], m[0][2] + m[1][2] + m[2][2], m[0][0] + m[1][1] + m[2][2], m[0][2] + m[1][1] + m[2][0]]
    q.write("Win" if 3 in p else "Lose" if -3 in p else "Draw")
