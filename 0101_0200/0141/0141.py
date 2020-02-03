from collections import deque
with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n = int(f.readline())
    m = [[x == "1" for x in f.readline().split()] for i in range(n)]
    s = "YES"
    e = 0
    st = deque([0])
    lst = [False for i in range(n)]
    lst[0] = True
    while st:
        v = st.pop()
        lst[v] = True
        for i in range(n):
            if m[v][i]:
                if lst[i]:
                    s = "NO"
                    break
                else:
                    st.append(i)
                    m[i][v] = False
                    e += 1
    q.write("NO" if e != n - 1 else s)
