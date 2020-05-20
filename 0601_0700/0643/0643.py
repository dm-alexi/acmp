with open("input.txt", "r") as f, open("output.txt", "w") as q:
	n = int(f.read())
	a = n
	while a:
		a &= a - 1
		n += 1
	q.write(str(n))
