with open("input.txt", "r") as f, open("output.txt", "w") as q:
    primes = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97]
    n, k = (int(x) for x in f.read().split())
    d = dict()
    c = []
    for i in primes:
        if k % i == 0:
            tmp = 0
            while k % i == 0:
                k //= i
                tmp += 1
            d[i] = tmp
    if k > 1:
        d[k] = 1
    for i, v in d.items():
        l = i
        tmp = 0
        while n // l > 0:
            tmp += n // l
            l *= i
        c.append(tmp // v)
    q.write(str(min(c)))
