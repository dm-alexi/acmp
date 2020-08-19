def bet(s):
	if len(s) == 4:
		if s == s[0] * 4:
			return 5
		if s[0] == s[3] and s[1] == s[2]:
			return 4
		if s[0:2] == s[2:4] or (s[0] == s[1] and s[2] == s[3]) or (s[0] == s[1] and s[0] == s[2]) or (s[0] == s[1] and s[0] == s[3]) or (s[0] == s[2] and s[0] == s[3]) or (s[1] == s[2] and s[1] == s[3]):
			return 3
		if s[0] == s[2] or s[1] == s[3]:
			return 2
	elif len(s) == 3:
		if s == s[0] * 3:
			return 3
		if s[0] == s[1] or s[1] == s[2] or s[0] == s[2]:
			return 2
	elif s[0] == s[1]:
			return 2
	return 0

with open("input.txt", "r") as f, open("output.txt", "w") as q:
	s = f.read().strip()
	p = [(s[:4], s[4:]), (s[:3], s[3:]), (s[:3], s[3:5], s[5:]), (s[:2], s[2:5], s[5:]), (s[:2], s[2:4], s[4:])]
	d = max((sum(bet(x) for x in t), t) for t in p)
	q.write("-".join(d[1]) + f"\n{d[0]}")
