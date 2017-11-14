#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct node{
	long int src;
	long int des;
	long int cost;
};
struct node make_node(long int src,long int des,long int cost){
	struct node s;
	s.src=src;
	s.des=des;
	s.cost=cost;
	return s;
}

long int num[10000];

struct compare{
	bool operator()(struct node a,struct node b){
		return a.cost>b.cost;
	}
};

void initialize(){
	for(long int i=0;i<10000;i++)
		num[i]=i;
}
long int root(int a){
	while(num[a]!=a)
		a=num[a];
	return a;
}

void union_(int a,int b){
	a=root(a);
	b=root(b);
	num[b]=a;
}

bool connected(int a,int b){
	a=root(a);
	b=root(b);
	if(a==b)
		return true;
	else
		return false;
}

long int kruskal(priority_queue<struct node,vector<struct node>,compare> p){
	long int sum=0;
	initialize();
	while(!p.empty()){
		struct node e=p.top();
		p.pop();
		if(connected(e.src,e.des))
			continue;
		else{
			union_(e.src,e.des);
			sum+=e.cost;
		}
	}
	return sum;
}

int main(){
	long int n,m,a,b,w;
	cin>>n>>m;
	priority_queue<struct node ,vector<struct node>, compare> p;
	while(m--){
		cin>>a>>b>>w;
		p.push(make_node(a,b,w));
	}
	cout<<kruskal(p)<<endl;
	return 0;
}