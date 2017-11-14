#include <cstdio>
#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
using namespace std;
int vi[100000];

int dfs(vector<vector<int> > v,int x){
	stack<int> s;
	int e;
	int cnt=0;
	s.push(x);
	vi[x]=1;
	while(!s.empty()){
		e=s.top();
		s.pop();
		cnt++;
		for(int i=0;i<v[e].size();i++){
			if(vi[v[e][i]]!=1){
				vi[v[e][i]]=1;
				s.push(v[e][i]);
			}
		}
	}
	return cnt;
}

int main(){
	int m,n;
	int a,b,x;
	cin>>n>>m;
	vector<vector<int> >v(n+1);
	while(m--){
		cin>>a>>b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	cin>>x;
	cout<<n-dfs(v,x)<<endl;
	return 0;
}