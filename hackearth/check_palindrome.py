s=input()
start=0
end=len(s)-1
flag=False
for i in range(0,len(s)//2):
    if(s[start+i]!=s[end-i]):
        flag=True
        break
if(flag):
    print("NO")
else:
    print("YES")
