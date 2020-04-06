with open("input.txt", "r") as f, open("output.txt", "w") as q:
    n, v, k = (int(x) for x in f.read().split())
    q.write(f"YES {(2 * v - (n - 1) * k) * n // 2}" if v / k + 1 > n else f"NO {(v + v % k) * int(v / k + 1) // 2}")
