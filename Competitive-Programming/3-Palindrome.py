n = int(input())

s = ""
i = 0
t = 0

if n%2==0:
    while i < n:
        if(t==0):
            s = s + "aa"
            i += 2
            t=1
        else:
            s = s + "bb"
            i += 2
            t=0
    print(s,end="")
else:
    k = (int)(n/2)
    m=2*k
    while i < m:
        if(t==0):
            s = s + "aa"
            i += 2
            t=1
        else:
            s = s + "bb"
            i += 2
            t=0
    if(t==0):
        s=s+'a'
    else:
        s=s+'b'
    print(s,end="")