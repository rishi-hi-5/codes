#include<cstdio>
#include<iostream>

using namespace std;
//is it a tree
//no of nodes and no of edges
def printGraph(graph):
    for i in range(0,n+1):
        print(graph[i])
    print("\n")

def dfs(graph,visit,start):
    checked=1
    visit[start]=1
    print(visit)
    for i in range(0,n+1):
        print(start,i)
        if(start==i):
            continue
        elif(graph[start][i]==1 and visit[i]!=1):
            if(dfs(graph,visit,i)):
                print("FOUND")
                return True
        elif(graph[start][i]==1 and visit[i]==1):
            print("FOUND")
            return True
    return False
int main(){
	
	int n,int m;
	bool cycle_found=false;
	scanf("%d %d",&m,&n);
	int graph
	return 0;
}
graph=[[0 for i in range(0,n+1)] for j in range(0,n+1)]
visited=[0 for i in range(0,n+1)]
for i in range(0,m):
    k,l=map(int,input().split(" "))
    graph[k][l]=1
print("graph after initializations")
printGraph(graph)
print(visited)
print("graph goes for iteration")
for i in range(0,n+1):
    print(i)
    print(visited)
    if (visited[i]!=1 and dfs(graph,visited,i)):
        cycle_found=True
        print("NO")
        break

if cycle_found==False:
    print("YES")
