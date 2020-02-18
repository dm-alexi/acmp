with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n = int(f.readline()) - 1
    k = 0
    while n:
        k += n & 1
        n >>= 1
    q.write(str(k % 3))
    
