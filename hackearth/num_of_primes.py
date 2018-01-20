isprime=[0 for i in range(0,1000001)]
t=int(input())
cnt=0
for i in range(2,t+1):
    if(isprime[i]==0):
        isprime[i]=1
        cnt+=1
    else:
        continue
    for j in range(i,t+1):
        if(i*j>t):
            break
        isprime[i*j]=-1
        
print(cnt)