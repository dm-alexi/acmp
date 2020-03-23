with open("input.txt", "r") as f, open("output.txt", "w") as q:
    d = {' ' : 4, '.' : 5, ';' : 7, ',' : 2, '(' : 1, ')' : 1, '+' : 3, '-' : 3, '=' : 3, "'" : 3, '"' : 3, '{' : 8, '}' : 8, '[' : 8, ']' : 8, '<' : 8, '>' : 8}
    dig = "0123456789"
    alpha = "abcdefghijklmnopqrstuvwxyz"
    ALPHA = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    q.write(str(sum(d[l] if l in d else 13 - int(l) if l in dig else (alpha.index(l) + 1) // 10 + (alpha.index(l) + 1) % 10 if l in alpha else (ALPHA.index(l) + 1) // 10 + (ALPHA.index(l) + 1) % 10 + 10 if l in ALPHA else 0 for l in f.read())))
