t=int(input())
while(t!=0):
    n,k,q=list(map(int,input().strip().split()))
    a=list(map(int,input().strip().split()))
    
    if (n%k)!=0:
    	t=t-1
    	print("NO")
    	continue
    seg_size=n//k
    b=0
    c=seg_size
    sub=[]
    res=[]
    
    for i in range(0,k):
    	sub=a[b:c]
    	sub.sort()
    	res.append(sub[-1])
    	sub=[]
    	b=c
    	c=c+seg_size
    res.sort()
    if(res[0]<q):
    	print(res[0])
    else:
    	print("NO")
    t=t-1