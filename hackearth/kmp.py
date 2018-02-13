p=input()
t=input()
pn=[0 for i in range(0,len(p))]

p1=0
p2=p1+1
f=0
while(p2<len(p)):
    if(p[p1]==p[p2]):
        f=1
        pn[p2]=p1+1
        p1+=1
        p2+=1
    elif f==0:
        p2+=1
    else:
        while(p[p1]!=p[p2]):
            if p1==0:
                p2+=1
                break
            p1=pn[p1-1]
cnt=0
i=0
j=0
while(j<len(t)):
    if(p[i]==t[j]):
        j+=1
        i+=1
        if(i>=len(p)):
            i=0
            j-=1
            cnt+=1
    else:
        if(i!=0):
            i=pn[i-1]
        else:
            j+=1

print(cnt)
    
