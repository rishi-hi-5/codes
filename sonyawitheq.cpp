#include<cstdio>
#include<iostream>
#include<vector>
#include<map>
using namespace std;

int main(){

	int n;
	int no;
	vector<int> v,temp;
	map<int,int> mymap;
	cin>>n;
	while(n--){
		cin>>no;
		v.push_back(no);
		mymap[no]++;
	}
	for(int i=0,j=1;j<v.size();i++,j++){
		temp.push_back(v.at(i)+v.at(j));
		mymap[v.at(i)+v.at[j]];
	}
	return 0;
}
