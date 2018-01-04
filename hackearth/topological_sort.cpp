/**
   Author:: Rushikesh Fanse
   Program:: Topological sort
   Algorithm:: using stack
*/

#include <cstdio>
#include <iostream>
#include <stack>
#include <cstring>
using namespace std;
//2d array stores graph
int arr[21][21];
//return not visited vertex
int all_visited(int v[],int size){
  for(int i=size;i>=1;i--){
    if(v[i]==0)
      return i;
  }
  return 0;
}

stack<int> vertex_stack;  
//do a topo sort and obtain
void dfs_topo(int num,int v[],int n){
  //check if the node in hand is already visited meaning its all child are visited
  if(v[num]==1)
    return;
  v[num]=1;
  //push the childrens
  for(int i=n;i>=1;i--){
    if(arr[num][i]==1 && v[i]==0){
      dfs_topo(i,v,n);
      vertex_stack.push(i);
    }
    
  }
}

void create_topo_stack(int v[],int n){
  int node;
  while(node=all_visited(v,n)){
    dfs_topo(node,v,n);
    vertex_stack.push(node);
  }
}

int main(){
  int n,m,a,b;
  cin>>n>>m;
  int v[n+1];
  memset(v,0,sizeof(v));
  for(int i=1;i<=m;i++){
    cin>>a>>b;
    arr[a][b]=1;
  }
  //create a topological ordered vertices list
  create_topo_stack(v,n);
  while(!vertex_stack.empty()){
    cout<<vertex_stack.top()<<" ";
    vertex_stack.pop();
  }
  cout<<endl;
}
