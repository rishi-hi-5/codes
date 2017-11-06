t=int(input())
while(t!=0):
    n=int(input())
    a=list(map(int,input().strip().split()))
    k=0
    i=0
    flag=0
    num=0
    while(i<len(a)):
        k=a[i]-1
        j=1
        
        while(j<=k and i+j<len(a)):
            if a[i+j]==a[i]:
                j+=1
                continue
            else:
                flag=1
                break
        if(flag==1 or (j<=k and i+j>=len(a))):
            flag=1
            break
        if j!=1:
            i+=j
        else:
            i+=1

        num+=1
    if(flag==1):
        print("Invalid Data")
    else:
        print(num)
    t-=1
