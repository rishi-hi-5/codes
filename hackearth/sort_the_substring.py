def encode(s):
    res=[]
    for i in s:
        res.append(ord(i)-97)
    return res
def decode(s):
    res=[]
    for i in s:
        res.append(chr(i+97))
    return res

t=int(input())
while t!=0:
    s,st,et=input().strip().split(" ")
    st=int(st)
    et=int(et)
    s_int=encode(s)
    l=s_int[st:et+1]
    l.sort()
    l.reverse()
    j=0
    for i in range(st,et+1):
        s_int[i]=l[j]
        j+=1
    s=decode(s_int)
    
    for i in s:
        print(i,end='')
    print()
    t-=1

