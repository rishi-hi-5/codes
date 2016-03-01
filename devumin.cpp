#include<cstdio>
#include<iostream>
#define MAX 18
#define gc getchar_unlocked
using namespace std;
int a[MAX][MAX],n;
int tot;
int read_int()
{
	char ch;
	ch=gc();
	while(ch<'0'||ch>'9') ch=gc();
	int ret=0;
	while(ch>='0'&& ch<='9')
	{
		ret=ret*10+ch-48;
		ch=gc();
	}
	return ret;
} 

int row[2]={0,1};
int col[2]={1,0};

void backtrack(int x,int y,int val)
{
	int x1,y1;
	cout<<"x y "<<x<<" "<<y<<"\n";
	val=val^a[x][y];
	if(x==n-1 && y==n-1)
	{
		cout<<val<<"\n";
		if(tot<val)
			tot=val;
	}
	else
	{
		for(int i=0;i<2;i++)
		{
			x1=x+row[i];	
			y1=y+col[i];
		
			if(x1>n-1 || y1>n-1)
				continue;

			backtrack(x1,y1,val);
		}
	}
}

int main()
{
	int val;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			a[i][j]=read_int();
	}

	backtrack(0,0,0);
	printf("%d\n",tot);
	return 0;
}
