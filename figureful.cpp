#include<cstdio>
#include<iostream>
#include<map>
#include<string>
#include<utility>
using namespace std;


int main(){
	long int t,q,x,y;
	string str;
	map<pair<int,int>,string> hashmap;
	cin>>t;
	while(t--){
		cin>>x>>y;
		cin>>str;
		hashmap[make_pair(x,y)]=str;
	}
	cin>>q;
	while(q--){
		cin>>x>>y;
		cout<<hashmap[make_pair(x,y)]<<endl;
	}
	return 0;
}
