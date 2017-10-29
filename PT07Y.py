#is it a tree
#no of nodes and no of edges
n,m=map(int,input().split(" "))
#def printGraph(graph):
#    for i in range(0,n+1):
#        print(graph[i])
#    print("\n")

def dfs(graph,visit,start):
    visit[start]=1
#    print(visit)
    for i in range(0,n+1):
#        print(start,i)
        if(start==i):
            continue
        elif(graph[start][i]==1 and visit[i]!=1):
            if(dfs(graph,visit,i)):
#                print("FOUND")
                return True
        elif(graph[start][i]==1 and visit[i]==1):
#            print("FOUND")
            return True
    return False

cycle_found=False
graph=[[0 for i in range(0,n+1)] for j in range(0,n+1)]
visited=[0 for i in range(0,n+1)]
nos=[]
for i in range(0,m):
    k,l=map(int,input().split(" "))
    graph[k][l]=1
    nos.append(k)
    nos.append(l)
nos=set(nos)
#print("graph after initializations")
#printGraph(graph)
#print(visited)
#print("graph goes for iteration")
#print(visited)
i=next(iter(nos))
if (dfs(graph,visited,i)):
    cycle_found=True
    print("NO")

if(cycle_found==False):
    count=0
    for i in range(0,n+1):
        if (visited[i]==1):
            count+=1

    if count!=n:
        print("NO")
    else:
        print("YES")
