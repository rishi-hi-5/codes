#include <iostream>
#include <cstring>
#include <stack>
#include <cstdio>
using namespace std;
int a[100][100],v[100][100]={0},m,n;
int x[4]={1,0,-1,0};
int y[4]={0,1,0,-1};

struct node{
    int x,y;
};
bool valid(int i,int j,int k,int old){
    if(i+x[k]<0||j+y[k]<0||i+x[k]>=m||j+y[k]>=n||v[i+x[k]][j+y[k]]!=0||a[i+x[k]][j+y[k]]!=old)
        return false;
    return true;
}
void bfs(int xx,int yy,int k){
    stack<node> s;
    int old;
    node e,ne;
    e.x=xx;
    e.y=yy;
    s.push(e);
    old=a[e.x][e.y];
    while(!s.empty()){
        e=s.top();
        s.pop();
        v[e.x][e.y]=1;
        a[e.x][e.y]=k;
        for(int i=0;i<4;i++){
            if(valid(e.x,e.y,i,old)){
                ne.x=e.x+x[i];
                ne.y=e.y+y[i];
                s.push(ne);
            }
        }
    }
}

int main() {
	int t,x,y,k;
	scanf("%d",&t);
	while(t--){
        scanf("%d %d",&m,&n);
	    for(int i=0;i<m;i++){
	        for(int j=0;j<n;j++){
	            scanf("%d",&a[i][j]);
	        }
	    }
        scanf("%d %d %d",&x,&y,&k);	    
	    bfs(x,y,k);
	    for(int i=0;i<m;i++){
	        for(int j=0;j<n;j++){
	            v[i][j]=0;
                if(i==m-1 and j==n-1)
	                printf("%d",a[i][j]);
                else
                    printf("%d ",a[i][j]);
	        }
	    }
        printf("\n");
	}
	return 0;
}