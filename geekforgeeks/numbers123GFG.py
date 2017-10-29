t=int(input())
while(t!=0):
    n=input()
    l=input().split()
    flag=0
    for i in l:
        for j in ['1','2','3']:
            if j in i:
                flag=1
                if j!='3':
                    print(i,end=' ')
                else:
                    print(i)
                break
    if flag==0:
        print("-1")
    t-=1