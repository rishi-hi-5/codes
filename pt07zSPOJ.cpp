#include<cstdio>
#include<vector>

using namespace std;

vector<vector<int> > adjlist;
int dfs(int i){
	int cnt;
	for(int j=0;j<adjlist[i].size();j++){
		cnt++;
		dfs(j);
	}
	return cnt;
}

int main(){
	int no;
	int max=0,val;
	int m,n;
	scanf("%d",&no);
	adjlist.resize(no);
	no--; 
	while(no--){
		scanf("%d",&m);
		scanf("%d",&n);
		adjlist[m].push_back(n);
		adjlist[n].push_back(m);
	}
	for(int i=0;adjlist.size();i++){
		if(max<(val=dfs(i))){
			max=val;
		}
	}
	return 0;
}