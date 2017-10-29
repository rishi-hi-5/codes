n=int(input())
num=n

def check_attacking(mat,qx,qy):
    i=0
    while(i!=len(q)):
        qxx=q[i][0]
        qyy=q[i][1]
        if(qxx-qx==0 or qyy-qy==0 or abs(qxx-qx)==abs(qyy-qy)):
            return True
        i+=1
    return False

def nqueens(n,mat):
    global num
    global q
    if n==0:
        return True
    #1 denotes space is taken and 2 denotes queen
    for i in range(0,num):
        for j in range(0,num):
            if(check_attacking(mat,i,j)==False):
                mat[i][j]=1
                q.append([i,j])
                n-=1
                if(nqueens(n,mat)):
                    return True
                q=q[:len(q)-1]
                n+=1
                mat[i][j]=0
    return False
    
def print_me(l):
    for i in range(0,len(l)):
        if(i!=len(l)-1):
            print(l[i],end=' ')
        else:
            print(l[i],end='\n')
    

mat=[[0 for i in range(0,n)] for i in range(0,n)]
q=[]
if nqueens(n,mat):
    print("YES")
    for i in range(0,n):
        print_me(mat[i])
else:
    print("NO")