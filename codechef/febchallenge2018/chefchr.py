def check_if_contains_chef_perm(st):
    li=['c','h','e','f']
    for i in st:
        if i in li:
            li.remove(i)
    if(len(li)==0):
        return True
    else:
        return False

t=int(input())
while(t!=0):
    s=input()
    i=0
    cnt=0
    while(i+4<=len(s)):
        if(check_if_contains_chef_perm(s[i:i+4])):
            cnt+=1
        i+=1
    if(cnt==0):
        print("normal")
    else:
        print("lovely")
        print(cnt)
    t-=1
