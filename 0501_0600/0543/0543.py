with open("input.txt", "r") as f, open("output.txt", "w") as q:
	n, w, d, p = (int(x) for x in f.read().split())
	s = (w * n * (n - 1) // 2 - p) // d
	q.write(str(s if s else n))
