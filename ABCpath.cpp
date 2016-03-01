#include<cstdio>
#include<iostream>
#include<queue>
#define MAX 51
using namespace std;

int max_t,count;
int m,n;
struct coord{
	int x;
	int y;
};
queue<coord> q;
void visit(int x, int y ,int a[][MAX],int val){
	coord c,temp;
	if(x<0||x>=m||y<0||y>=n||a[x][y]!=val+1){
		return;
	}
	else{
		//cout<<"=="<<a[x][y]<<" "<<val<<endl;
		temp=q.front();
		//cout<<temp.x<<" "<<temp.y;
		if(q.empty()||a[x][y]!=a[temp.x][temp.y]){ 
		count++;
		c.x=x;
		c.y=y;
		q.push(c);
		}
	}
}
void bfs(int a[][MAX],int x,int y){
	int val;
	coord c;
	c.x=x;
	c.y=y;
	q.push(c);
	while(!q.empty()){
		c=q.front();
		//cout<<c.x<<" "<<c.y<<endl;
		val=a[c.x][c.y];
		q.pop();
		visit(c.x+1,c.y,a,val);
		visit(c.x-1,c.y,a,val);
		visit(c.x+1,c.y+1,a,val);
		visit(c.x+1,c.y-1,a,val);
		visit(c.x-1,c.y-1,a,val);
		visit(c.x,c.y+1,a,val);
		visit(c.x,c.y-1,a,val);
	}
	return;
}

int main(){
	int a[MAX][MAX];
	char ch;
	int flag=0;
	int local_count,test,cnt;
	cin>>m>>n;
	while(m!=0&&n!=0){
		local_count=0;
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				cin>>ch;
				a[i][j]=(int)ch-65;	
			}
		}
		cnt=0;
		flag=0;
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				count=0;
				if(a[i][j]=='0')
				{	bfs(a,i,j);
					cnt++;
				}
				if(local_count<count){
					local_count=count;
					test=cnt;
					flag=1;
				}	
			}
		}	
		if(flag!=1)
			test=1;
		cout<<"Case "<<test<<": "<<local_count+1<<endl;
		cin>>m>>n;
	}
}
