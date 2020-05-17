with open("input.txt", "r") as f, open("output.txt", "w") as q:
	n = int(f.read())
	i = 1
	if n % 4:
		q.write("1 1 0 1\n")
		if n > 1:
			q.write(f"1 2 2 {n if n % 4 == 3 else 0}\n")
		if n > 3 and n % 4 == 1:
			q.write(f"2 1 0 3\n2 2 4 {n}\n")
		i = 3 if n % 4 == 1 else 2
		n -= n % 2
	while 2 * i < n:
		q.write(f"{i} 1 {n} {2 * i - 1}\n{i} 2 {2 * i} {n - 1}\n")
		i += 1
		n -= 2
