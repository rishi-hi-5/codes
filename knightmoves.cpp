#include<acstdio>
#include<iostream>
#include<queue>
#include<string>
using namespace std;
//denotes x coordinate
b[8]={1,-1,-2,-2,-1,1,2,2};
//denotes y coordinate
c[8]={2,2,1,-1,-2,-2,1,-1};

void bfs(int a[][8],int visited[][8],string x){

}

int main(){
	int a[8][8]={0},visited[8][8]={0};
	int t;
	cin>>t;
	while(t--){
		string x,y;
		cin>>x>>y;
		a[x[0]-97][x[1]]=1;
		a[y[0]-97][y[1]]=2;
	}
	
	bfs(a,visited,x);

	return 0;
}
