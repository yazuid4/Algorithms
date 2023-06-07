from collections import defaultdict

n,m = map(int, input.split())

d = defaultdict(list)

for i in range(n):
	s = input()
	d[s].append(i+1)

for i in range(m):
	s = input()
	if s not in d:
		print(-1)
	else:
		for k in d[s]:
			print(k, end=" ")
		print()


