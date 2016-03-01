#include<cstdio>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<vector>
#define MAX 51
using namespace std;
char a[MAX][MAX];

struct coord{
	int x;
	int y;
};
int res;
int w,h;
int visitx[]={1,1,0,-1,-1,-1,0,1};
int visity[]={0,1,1,1,0,-1,-1,-1};
void dfs(int x,int y,int count){
	
	if(a[x][y]==(char)(count+65)){
		count++;
		if(res<count)
			res=count;
		for(int i=0;i<8;i++){
			if(x+visitx[i]<0||x+visitx[i]>=w||y+visity[i]<0||y+visity[i]>=h)
				continue;
			dfs(x+visitx[i],y+visity[i],count);
		}
	}
	else
		return;
}

int main(){	
	int min;
	int count;
	vector<struct coord> v;
	struct coord temp;
	cin>>w>>h;
	int test=1;
	while(w!=0||h!=0){
		min=0;
		res=0;
		for(int i=0;i<w;i++){
			for(int j=0;j<h;j++){
				cin>>a[i][j];
				if(a[i][j]=='A'){
					temp.x=i;
					temp.y=j;
					v.push_back(temp);
				}
			}
		}
		for(int i=0;i<v.size();i++){	
			count = 0;
			res=0;
			dfs((v.at(i)).x,(v.at(i)).y,count);
			if(res>min){
				min=res;
			}
		}
		cout<<"Case_"<<test<<":_"<<min<<endl;
		test++;
		memset(a,'\0',sizeof(a));
		v.clear();
		cin>>w>>h;
	}	
	return 0;
}
