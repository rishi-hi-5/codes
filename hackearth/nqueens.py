n=int(input())
num=n

def check_attacking(mat,qx,qy):
    global num
    print("result for attacking")
    for i in range(0,num):
        if(qx+qy<num):
            c1=abs(qx+qy)+1
            c2=abs(qx+(num-1)-qy)+1
        else:
            c1=abs(qx-qy)+1
            c2=abs(qx-(num-1)-qy)+1
        print(i,qx,qy,mat[(qx+i)%num][qy]!=0,mat[qx][(qy+i)%num]!=0,mat[(qx+i)%c2][(qy+i)%c2]!=0,mat[(qx-i)%c2][(qy+i)%c2]!=0)
        if(mat[(qx+i)%num][qy]!=0 or mat[qx][(qy+i)%num]!=0 or mat[(qx+i)%c2][(qy+i)%c2]!=0 or mat[(qx-i)%c2][(qy+i)%c2]!=0):
            return True
    return False    

def print_mat(mat):
    global num
    print()
    print("new mat starts")
    for i in range(0,num):
        for j in range(0,num):
            print(mat[i][j],end=' ')
        print()


def nqueens(n,mat):
    global num
    if n==0:
        return True
    #1 denotes space is taken and 2 denotes queen
    for i in range(0,num):
        for j in range(0,num):
            print_mat(mat)
            if(check_attacking(mat,i,j)==False):
                mat[i][j]=2
                n-=1
                if(nqueens(n,mat)):
                    return True
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
if nqueens(n,mat):
    print("YES")
    for i in range(0,n):
        print_me(mat[i])
else:
    print("NO")