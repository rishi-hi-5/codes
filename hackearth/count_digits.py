s=input()
a=[0 for i in range(0,10)]
for i in s:
    a[ord(i)-48]+=1
for i in range(0,10):
    print(i," ",a[i])
