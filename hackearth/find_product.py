n= int(input())
prd=1
a=map(int,input().split(" "))
for i in a:
    prd*=i
    prd%=1000000007
print(prd)
