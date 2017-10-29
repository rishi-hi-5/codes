t=int(input())
ignore=['a','e','i','o','u']

while t!=0:
    s=input()
    cnt=0
    for i in range(4,len(s)-4):
        if s[i] in ignore:
            continue
        else:
            print(s[i])
            cnt+=1
    print(cnt)
    news=""
    news+=str(cnt+4)
    news+='/'
    news+=str(len(s))
    print(news)
    t-=1
