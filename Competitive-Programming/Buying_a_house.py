n,m,k = map(int, input().split())
l = list(map(int, input().split()))

d=n-1

for i in range(n):
	if i != m-1:
		if l[i]<=k and l[i]>0:
			d = min(d,abs(m-1-i))

print(d*10, end="")