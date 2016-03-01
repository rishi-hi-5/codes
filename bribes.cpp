#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#define MAX 100000

using namespace std;
int main(){
	long long int n,x,y;
	int val;
	cin>>n;
	int mat[MAX][MAX];
	memset(mat,2,sizeof(mat));
	
	for(long long int i=0;i<n;i++){
		//scanf("%lld%lld%d",&x,&y,&val);
		cin>>x>>y>>val;
		mat[x][y]=val;
	}
	for(long long int i=0;i<n;i++){
		for(long long int j=0;j<n;j++)
			printf("%d ",mat[i][j]);
		printf("\n");
	}
}
