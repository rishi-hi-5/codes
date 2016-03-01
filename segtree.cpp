#include<cstdio>
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

vector<int> s;
int  buildSegTree(int st,int et,vector<int> v,int i){
	if(st==et)
	{
		s.at(i)=v.at(st);
		return v.at(st);
	}
	else
	{
		int mid=(st+et)/2;
		s.at(i)=buildSegTree(st,mid,v,i*2+1)+buildSegTree(mid+1,et,v,i*2+2);
	}
	return s.at(i);
}
int getSum(int a,int b,int st,int et,int i){
	if(a<=st&&b>=et)
		return s.at(i);
	else if(a>et||b<st)
		return 0;
	else
	{
		int mid=(st+et)/2;
		return getSum(a,b,st,mid,i*2+1)+getSum(a,b,mid+1,et,i*2+2);
	}
}
void updateTree(int diff,int pos,int st,int et,int i){
	if(pos<st||pos>et)
		return;

	s.at(i)+=diff;
	if(st!=et){
		int mid=(st+et)/2;
		updateTree(diff,pos,st,mid,i*2+1);
		updateTree(diff,pos,mid+1,et,i*2+2);
	}
}
int main(){
	
	vector<int> v;
	int diff;
	int temp;
	int no;
	int pos,val;
	cin>>no;
	while(no--){
		cin>>temp;
		v.push_back(temp);
	}
	int size=2*(int)(pow(2,((int)ceil(log2(v.size())))))-1;
	s.resize(size);
	buildSegTree(0,v.size()-1,v,0);
	cout<<"your tree is ready"<<endl;
	int a,b;
	cin>>a>>b;
	cout<<getSum(a,b,0,v.size()-1,0)<<endl;
	cin>>pos>>val;
	diff=val-v.at(pos);
	v.at(pos)=val;
	updateTree(diff,pos,0,v.size()-1,0);
	return 0;
}
