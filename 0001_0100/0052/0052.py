with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n = int(f.read())
    a = 0
    for i in range(3):
        a += n % 10
        n //= 10
    for i in range(3):
        a -= n % 10
        n //= 10
    q.write("NO" if a else "YES")

        
