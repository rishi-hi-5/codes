#include<cstdio>
#include<iostream>
#include<cstdlib>
using namespace std;

int main(){
	int r,c;
	scanf("%d%d",&r,&c);
	
	int*a;

	a=(int*)malloc(sizeof(int)*r*c);
	
	for(int i=0;i<r;i++)
	{	
		for(int j=0;j<c;j++){
			cin>>a[i][j];
		}
	}
	for(int i=0;i<r;i++)
	{	
		for(int j=0;j<c;j++){
			cout<<a[i][j];
		}
	}
	return 0;
}
