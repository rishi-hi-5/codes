#include<cstdio>
#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	vector<int> v;
	map<int,int> mymap;
	int t;
	int no;
	cin>>t;
	while(t--){
		cin>>no;
		v.push_back(no);
	}
	//sort(v.begin(),v.end());
	for(int i=0;i<v.size();i++){
		for(int j=i+1;j<v.size();j++)
			mymap[abs(v.at(j)-v.at(i))]++;
	}
	cout<<mymap.size()<<endl;
}
