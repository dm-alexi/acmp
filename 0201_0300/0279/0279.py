with open("input.txt", "r") as f, open("output.txt", "w") as q:
    s = f.readline().strip()
    d = {'(' : ')', '[' : ']'}
    st = []
    k = 0 if not s or s[0] in d else -1
    if k == 0:
        for l in s:
            if l in d:
                st.append(l)
            elif not st:
                k = -1
                break
            elif l != d[st.pop()]:
                k += 1
    q.write("-1" if st else f"{k}")
                        
