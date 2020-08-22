with open("input.txt", "r") as f, open("output.txt", "w") as q:
	lines = [s[:-1] for s in f.readlines()[:-1]]
	lines.sort()
	m = 0
	for i in range(1, len(lines)):
		for j in range(i):
			if lines[i].startswith(lines[j]) and lines[i][len(lines[j]):] in lines:
				m += 1
				break
	q.write(str(m))