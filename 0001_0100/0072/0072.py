with open("input.txt", "r") as f, open("output.txt", "w") as q:
    s = list(f.read().strip())
    l = len(s)
    k, i = l - 2, l - 1
    while s[k] >= s[k + 1]:
        k -= 1
    while s[i] <= s[k]:
        i -= 1
    s[k], s[i] = s[i], s[k]
    q.write("".join(s[:k+1] + s[k+1:][::-1]))
