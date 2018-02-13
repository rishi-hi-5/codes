def count_str_e_o(st):
    ec=0
    oc=0
    for i in st:
        if i=='E':
            ec+=1
        else:
            oc+=1
    return ec,oc

t=int(input())
while(t!=0):
    n,m,x,k=list(map(int,input().strip().split()))
    st=input()
    ec,oc=count_str_e_o(st)
    if(m==0):
        print("no")
        t-=1
        continue
    for i in range(1,m+1):
        if(n==0):
            break
        if(i%2==0 and ec>0):
            ec-=x
            n-=x
        elif(i%2==1 and oc>0):
            oc-=x
            n-=x

    if(n<=0):
        print("yes")
    else:
        print("no")
        
    t-=1
