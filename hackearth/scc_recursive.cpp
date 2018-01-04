/**
   Author:: Rushikesh Fanse
   Program:: Strongly Connected Components 
   Algorithm:: Kosarajus algo
*/

#include <cstdio>
#include <iostream>
#include <stack>
#include <vector>
#include <cstring>
using namespace std;
//2d array stores graph
int arr[16][16];
int rev_arr[16][16];
//return not visited vertex
int all_visited(int v[],int size){
  for(int i=1;i<=size;i++){
    if(v[i]==0)
      return i;
  }
  return 0;
}

stack<int> reverse_stack(stack<int> st){
  stack<int> rev;
  while(!st.empty()){
    rev.push(st.top());
    st.pop();
  }
  return rev;
}
stack<int> vertex_stack;  
//do a topo sort and obtain
void dfs_topo(int num,int v[],int n){
  //check if the node in hand is already visited meaning its all child are visited
  if(v[num]==1)
    return;
  v[num]=1;
  //push the childrens
  for(int i=1;i<=n;i++){
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

stack<int>aux_stack;
void populate_aux(){
  int ele;
  while(!vertex_stack.empty()){
    ele=vertex_stack.top();
    vertex_stack.pop();
    populate_aux();
    aux_stack.push(ele);
  }
}

void clear_primary_stack(){
  while(!vertex_stack.empty()){
    vertex_stack.pop();
  }
}

/*
Find c-d
C= Sum of number of nodes in all Strongly Connected Components with odd number of nodes.
D= Sum of number of nodes in all Strongly Connected Components with even number of nodes.*/
int find_cal(int v[],int n){
  int odd_count=0,even_count=0,node;
  populate_aux();
  while(!aux_stack.empty()){
    int ele=aux_stack.top();
    aux_stack.pop();
    if(v[ele]==1)
      continue;
    dfs_topo(ele,v,n);
    vertex_stack.push(ele);
    if(vertex_stack.size()%2==0)
      even_count+=vertex_stack.size();
    else
      odd_count+=vertex_stack.size();
    clear_primary_stack();
  }
  return odd_count-even_count;
}

void copy_arr(){
  for(int i=0;i<16;i++){
    for(int j=0;j<16;j++){
      arr[i][j]=rev_arr[i][j];
    }
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
    rev_arr[b][a]=1;
  }
  //create a topological ordered vertices list
  create_topo_stack(v,n);
  // reinitialize the dfs array for second dfs traversal
  memset(v,0,sizeof(v));
  //copy reverse array in array
  copy_arr();
  //find the solution of problem statement
  cout<<find_cal(v,n)<<endl;
}
