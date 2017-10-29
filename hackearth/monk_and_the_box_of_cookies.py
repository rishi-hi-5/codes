t=int(input())
while(t!=0):
    bits=[0 for i in range(0,32)]
    n=int(input())
    while(n!=0):
        no=int(input())
        cnt=0
        while(no!=0):
            cnt+=1
            if(no&1==1):
                bits[cnt]+=1
            no=no>>1
        n-=1
    max_cnt=0
    max_i=0
    for i in range(0,32):
        if(bits[i]>max_cnt):
            max_cnt=bits[i]
            max_i=i
    print(max_i)
    t-=1