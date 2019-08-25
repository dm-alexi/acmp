def sim(a):
    if a == 2:
        return True
    if a == 1 or a % 2 == 0:
        return False
    for i in range(3, int(a ** 0.5) + 1, 2):
        if a % i == 0:
            return False
    return True

with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n = int(f.read())
    m, k, i = 0, 1, 3
    while True:
        if sim(i):
            k += 1
            if sim(k):
                m += 1
                if m == n:
                    break
        i += 2
    q.write(str(i))

        
    
           
        
