#include<cstdio>
#include<iostream>
#include<queue>
#include<cstdlib>
#include<cstring>

#define MAX 102
using namespace std;

int m,n;
int b,c,d;
int visitx[]={1,0,-1,0};
int visity[]={0,1,0,-1};
int a[MAX][MAX];
int visited[MAX][MAX];
struct coxy{
	int x;
	int y;
	int ele;
};

class compare{
	public:
		bool operator()(struct coxy &p1,struct coxy &p2)const{
				return p1.ele>p2.ele;
		}
};
priority_queue <struct coxy,vector<struct coxy>,compare> q;
void visit(int x,int y,struct coxy xy){
	struct coxy co;
	if(x<1||x>=m+1||y<1||y>=n+1||visited[x][y]==1)
		return;
	else
	{
		visited[x][y]=1;
		co.x=x;
		co.y=y;
		co.ele=a[x][y]+xy.ele;
		q.push(co);	
	}
}

int dijkstras(int temp){
	struct coxy var;
	struct coxy co;
	co.x=1;
	co.y=1;
	co.ele=a[1][1];
	visited[1][1]=1;
	q.push(co);
	while(!q.empty()){
		var=q.top();
		q.pop();
		if(d==var.x &&b==var.y){
			if(c-(var.ele+temp)>=0)
				return c-(var.ele+temp);
			else
				return -1;
		}
		for(int i=0;i<4;i++){
			visit(var.x+visitx[i],var.y+visity[i],var);
		}	
	}
}
int main(){

	int temp;
	int t;
	int res;
	cin>>t;
	while(t--){
		cin>>m>>n;
		for(int i=1;i<=m;i++){
			for(int j=1;j<=n;j++){
				cin>>a[i][j];
			}
		}
		cin>>d>>b>>c;
		temp=a[d][b];
		a[d][b]=0;
		res=dijkstras(temp);
		if(res==-1)
			cout<<"NO\n";
		else
		{
			cout<<"YES\n";
			cout<<res<<endl;
		}
		memset(a,0,sizeof(a));
		memset(visited,0,sizeof(visited));
		while(!q.empty())
			q.pop();
	}
	return 0;
}
