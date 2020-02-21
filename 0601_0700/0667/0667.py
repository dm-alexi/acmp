with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n, m, k = (int(x) for x in f.readline().split())
    q.write(str((m + n) // k + ((m + n) % k > 0)) if k > 2 and m >= 2 * (n // (k - 2) + (n % (k - 2) > 0)) else '0')
