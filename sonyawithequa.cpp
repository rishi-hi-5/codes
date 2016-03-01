#include<cstdio>
#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#define gc getchar_unlocked
using namespace std; 
int read_int()
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
int main(){
	vector<int> v;
	map<int,int> mymap;
	int t;
	int no;
	t=read_int();
	while(t--){
		no=read_int();
		v.push_back(no);
	}
	//sort(v.begin(),v.end());
	for(int i=0;i<v.size();i++){
		for(int j=i+1;j<v.size();j++)
			mymap[abs(v.at(j)-v.at(i))]++;
	}
	cout<<mymap.size()<<endl;
}
