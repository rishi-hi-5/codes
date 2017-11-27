#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
using namespace std;
long int di[10002];
long int vi[10002];

struct node{
	long int no;
	long int cost;
};

struct comparator{
	bool operator()(struct node a,struct node b){
		return a.cost>b.cost;
	}	
};


void shp(vector<vector<struct node> > a){
	priority_queue<struct node,vector<struct node>,comparator> q;
	struct node e,newe;
	di[1]=0;
	e.no=1;
	e.cost=0;
	q.push(e);
	while(!q.empty()){
		e=q.top();
		q.pop();
		if(vi[e.no]==1)
			continue;
		vi[e.no]=1;
		for(long int i=0;i<a[e.no].size();i++){
			if(di[a[e.no][i].no]>di[e.no]+a[e.no][i].cost ){
				di[a[e.no][i].no]=di[e.no]+a[e.no][i].cost;
				newe.no=a[e.no][i].no;
				newe.cost=di[a[e.no][i].no];
				q.push(newe);
			}
		}
	}
}

struct node make_node(long int no,long int cost){
	struct node n;
	n.no=no;
	n.cost=cost;
	return n;
}

int main(){
	long int n,m,a,b,w;
	fill_n(di,10002,INT_MAX);
	cin>>n>>m;
	vector<vector<struct node> >v(n+1);
	for(long int i=0;i<m;i++){
		cin>>a>>b>>w;
		v[a].push_back(make_node(b,w));
	}
	shp(v);
	for(long int i=2;i<=n;i++){
		cout<<di[i]<<" ";
	}
	cout<<endl;
	return 0;
}