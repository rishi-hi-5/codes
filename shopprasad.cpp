
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * **
* Author : Prasad J Ghangal										*
* Title : Spoj-Shopping		 									*
* Category : Shortest Path										*
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <queue>
#include <vector>
#define gc getchar_unlocked

using namespace std;
char a[30][30];
int h,w;
class abc
{
	public:
		int row,col;
		int cost;
	abc(int x,int y,int z)
	{
		row=x;col=y;
		cost=z;
	}
};

int dr[]={-1,0,0,1};
int dc[]={0,-1,1,0};

struct comp
{
	bool operator()(abc& x,abc& y)
	{
		return x.cost>y.cost;
	}
};

int fin()
{
	int res=0;
	register char c=gc();
	while(c<'0' || c>'9')
		c=gc();
	while(c>='0' && c<='9')
	{
		res=res*10+(c-48);
		c=gc();
	}
	return res;
}

int bfs(int x,int y)
{
	priority_queue<abc,vector<abc>,comp> q1;
	int nr,nc;
	abc obj(0,0,0);
	char visited[30][30];
	memset(visited,'0',sizeof(visited));
	q1.push(abc(x,y,0));
	visited[x][y]='1';
	while(!q1.empty())
	{
		obj=q1.top();
		q1.pop();
		if(a[obj.row][obj.col]=='D')
			return obj.cost;
		else
		{
			for(int i=0;i<4;i++)
			{
				nr=obj.row+dr[i];
				nc=obj.col+dc[i];
				if(nr<0 || nr>=h || nc<0 || nc>=w)
					continue;
				if(visited[nr][nc]=='1')
					continue;
				if(a[nr][nc]=='X')
					continue;
				visited[nr][nc]='1';
				if(a[nr][nc]=='D')
					q1.push(abc(nr,nc,obj.cost));
				else
					q1.push(abc(nr,nc,(obj.cost+(a[nr][nc]-48))));
			}
		}
	}
}


int main()
{
	int i,j;
	char f;
	while(1)
	{
		w=fin();
		h=fin();
		if(w==0 && h==0)
			break;
		f='0';
		for(i=0;i<h;i++)
			scanf("%s",a[i]);
		
		for(i=0;i<h;i++)
		{
			for(j=0;j<w;j++)
			if(a[i][j]=='S')
			{
				f='1';
				break;
			}
			if(f=='1')
				break;
		}
		printf("%d\n",bfs(i,j));

/*		for(i=0;i<h;i++)
		{
			printf("\n");
			for(j=0;j<w;j++)
				printf("%c ",a[i][j]);
		}
		cout<<"\n";
		
*/
	}
	return 0;
}