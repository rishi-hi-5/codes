#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#define MAX 25
#include<queue>
using namespace std;
struct xyco{
	int x;
	int y;
	int ele;
};

class compare{
	public:
		bool operator()(struct xyco &p1,struct xyco &p2)const{
				return p1.ele>p2.ele;
		}
};

int mat[MAX][MAX];
priority_queue <struct xyco,vector<struct xyco>,compare> q;
int visitx[]={-1,1,0,0};
int visity[]={0,0,1,-1};
int a,b;
int visited[MAX][MAX];
void visit(int x,int y,xyco co){
	if(x<0||x>=b||y<0||y>=a||visited[x][y]==1)
		return;
	else{
		struct xyco loc;
		loc.x=x;
		loc.y=y;
		visited[x][y]=1;
		loc.ele=mat[x][y]+co.ele;
		q.push(loc);
	}
}

struct xyco des;
int dijkstras(struct xyco loc){
	struct xyco temp;
	int sum=0;
	q.push(loc);
	while(!q.empty()){
		//cout<<q;
		temp=q.top();
		//sum+=mat[temp.x][temp.y];
		//cout<<temp.x<<" "<<temp.y<<" "<<temp.ele<<endl;
		q.pop();
		if(des.x==temp.x&&des.y==temp.y)
			return temp.ele;
		for(int i=0;i<4;i++){
			visit(temp.x+visitx[i],temp.y+visity[i],temp);
		}
	}
	return 0;
}

int main(){

	char temp;
	struct xyco xy;
	int res;
	cin>>a>>b;
	while(a!=0||b!=0){
	q=priority_queue <struct xyco,vector<struct xyco>,compare> ();
		for(int i=0;i<b;i++){
			for(int j=0;j<a;j++){
				cin>>temp;
				//cout<<temp;
				if(temp=='S'){
					mat[i][j]=0;
					xy.x=i;
					xy.y=j;
					xy.ele=0;
					visited[i][j]=1;
				}
				else if(temp=='X'){
					mat[i][j]=999;
					visited[i][j]=1;
				}
				else if(temp=='D'){
					mat[i][j]=0;
					des.x=i;
					des.y=j;
					des.ele=0;
				}
				else{
					//cout<<i<<" "<<j<<" "<<mat[i][j]<<endl;
					mat[i][j]=(int)temp-48;
				}
			}
		}

		res=dijkstras(xy);
		while(!q.empty()) q.pop();
		memset(mat,0,sizeof(mat));
		memset(visited,0,sizeof(visited));
		cout<<res<<endl;
		scanf("%c",&temp);
		cin>>a>>b;
	}
}
