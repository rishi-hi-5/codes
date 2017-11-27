x=[1,0,-1,0]
y=[0,1,0,-1]
def dfs(mat ,vis, i,j,di,dj):
    global x
    global y
    if i==di and j==dj:
        return True
    
    for k in range(0,4):
        if((not (i+x[k]<0 or i+x[k]>di or j+y[k]<0 or j+y[k]>dj)) and vis[i+x[k]][j+y[k]]==0 and mat[i+x[k]][j+y[k]]!=0):
            vis[i+x[k]][j+y[k]]=1
            if(dfs(mat,vis,i+x[k],j+y[k],di,dj)):
                return True
    return False
n,m=list(map(int,input().strip().split(" ")))
mat=[[0 for i in range(0,n)] for j in range(0,m)]
vis=[[0 for i in range(0,n)] for j in range(0,m)]
for i in range(0,n):
    l=list(map(int,input().strip().split(" ")))
    for j in range(0,m):
        mat[i][j]=l[j]
vis[0][0]=1
if dfs(mat,vis,0,0,n-1,m-1)==True :
    print("Yes")
else:
    print("No")