#include<cstdio>
#include<iostream>
#include<vector>
#include<cstdlib>
#include<cstring>
#include<set>
#define MAX 104
#define gc getchar_unlocked
using namespace std;
long int read_int()
{
	char ch;
	ch=gc();
	while(ch<'0'||ch>'9') ch=gc();
	long int ret=0;
	while(ch>='0'&& ch<='9')
	{
		ret=ret*10+ch-48;
		ch=gc();
	}
	return ret;
} 
int a[MAX][MAX];
bool visited[MAX];
set<int> s;

void dfs(int i){
	int flag=0;
	if(visited[i]==true){
		//s.insert(i);
		return;
	}
	visited[i]=true;
	//s.insert(i);
	for(int j=1;j<=100;j++){
		if(visited[j]==false&&(a[i][j]==1)){
			flag=1;
			dfs(j);
		}
	}
	if(flag==0)
		s.insert(i);
}

int main(){
	int n,m,dep,val,dep_val;
	vector<int> v;
	n=read_int();
	m=read_int();
	for(int i=0;i<m;i++){
		val=read_int();
		dep=read_int();
		v.push_back(val);
		for(int j=0;j<dep;j++){
			dep_val=read_int();
			a[val][dep_val]=1;
		}
	}
	for(int i=1;i<=n;i++){
			dfs(i);			

		if(!s.empty()){
		cout<<*s.begin()<<" ";
		s.erase(s.begin()); 
		}
	}
	
	while(!s.empty()){
		cout<<*s.begin()<<" ";
		s.erase(s.begin()); 
		}
	
	cout<<endl;
	return 0;
}
