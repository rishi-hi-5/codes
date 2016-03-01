#include<cstdio>
#include<iostream>
#include<climits>
#include<queue>
#define MAX 25

using namespace std;

struct coord{
	int x;
	int y;
};

queue<coord> q;
int m,n;
void visit(int x,int y,int dist[][MAX],int visited[][MAX],int currentDist,int dim[][MAX]){
	coord c;

	if(x<0||x>=m||y<0||y>=n||visited[x][y]!=0)
		return;
	else
	{
		if(dist[x][y]>currentDist+dim[x][y]){
			dist[x][y]=dim[x][y]+currentDist;
			c.x=x;
			c.y=y;
			q.push(c);
		}
	}
}
int main(){
	char ch;
	coord c,f;
	int dist[MAX][MAX],dim[MAX][MAX],visited[MAX][MAX];
	cin>>n>>m;
	while(m!=0 || n!=0){		
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				cin>>ch;
				if(ch=='S'){
					dim[i][j]=0;
					c.x=i;
					c.y=j;
					q.push(c);
					visited[i][j]=0;
				}
				else if(ch=='D'){
					dim[i][j]=0;
					f.x=i;
					f.y=j;
					visited[i][j]=0;
				}
				else if(ch=='X'){
					dim[i][j]=-1;
					visited[i][j]=1;
				}
				else
				{
					visited[i][j]=0;
					dim[i][j]=(int)ch-'0';
				}
			}
		}
		
		for(int i=0;i<m;i++){
			for(int j=0;j<m;j++){
				dist[i][j]=99999;
			}
		}

		dist[c.x][c.y]=0;
		while(!q.empty()){

			c=q.front();
			q.pop();
			visit(c.x+1,c.y,dist,visited,dist[c.x][c.y],dim);
			visit(c.x-1,c.y,dist,visited,dist[c.x][c.y],dim);
			visit(c.x,c.y+1,dist,visited,dist[c.x][c.y],dim);
			visit(c.x,c.y-1,dist,visited,dist[c.x][c.y],dim);
		}
		if(dist[f.x][f.y]!=99999)
			cout<<dist[f.x][f.y]<<endl;
		else
			cout<<"1"<<endl;
		scanf("%c",&ch);
		cin>>n>>m;
	} 
}
