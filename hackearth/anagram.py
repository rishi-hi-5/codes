t=int(input())
while t!=0:
    s1=input()
    s2=input()
    h1=[0 for i in range(0,26)]
    h2=[0 for i in range(0,26)]
    for i in s1:
        h1[ord(i)-97]+=1

    for i in s2:
        h2[ord(i)-97]+=1
    cnt=0
    
    for i in range(0,26):
        cnt+=(abs(h1[i]-h2[i]))
    print(cnt)
    t-=1
