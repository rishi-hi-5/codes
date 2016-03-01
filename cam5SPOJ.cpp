#include<cstdio>
#include<iostream>
#include<vector>
#include<cstring>
#include<cstdlib>
using namespace std;

vector<vector<int> > adjlist;
int n,f;
bool visit[100000];
int cnt;
void dfs(int i){
	
	if(i<n)
	for(int j=0;j<adjlist[i].size();j++){	
			if(visit[adjlist[i].at(j)]==false){
				visit[adjlist[i].at(j)]=true;
				dfs(adjlist[i].at(j));	
			}
	}
}


int main(){
	int t;
	int s,d;
	cin>>t;
	while(t--){
		cnt=0;
		cin>>n;
		cin>>f;
		if(f==0)
		{	
			cout<<n<<endl;
			continue;
		}
		adjlist.resize(n);	
		for(int i=0;i<f;i++){
			cin>>s>>d;
			if(s<n&&d<n){
			adjlist[s].push_back(d);
			adjlist[d].push_back(s);
			}
	
		}
		for(int i=0;i<n;i++){
			if(visit[i]==false)
			{
				cnt++;
				visit[i]=true;
				dfs(i);
			}
		}	
		adjlist.clear();
		memset(visit,false,sizeof(visit));
		cout<<cnt<<endl;
	}
	return 0;
}
