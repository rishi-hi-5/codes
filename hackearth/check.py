a=[0 for i in range(0,n+1)]
res=[]
for i in range(2,n+1):
    if(a[i]==1):
        continue
    res.append(i)
    for j in range(2,n+1):
        if(i*j<=n):
            a[i*j]=1
#print(res)
for i in range(0,len(res)):
    if i!=len(res)-1:
        print(res[i],end=' ')
    else:
        print(res[i],end='\n')
