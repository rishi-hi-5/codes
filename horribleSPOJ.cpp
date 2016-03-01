#include<cstdio>
#include<iostream>
#include<vector>
#include<cmath>
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
vector<long int> s;
long int  buildSegTree(long int st,long int et,vector<long int> v,long int i){
	if(st==et)
	{
		s.at(i)=0;
		return 0;
	}
	else
	{
		long int mid=(st+et)/2;
		s.at(i)=buildSegTree(st,mid,v,i*2+1)+buildSegTree(mid+1,et,v,i*2+2);
	}
	return s.at(i);
}
long int getSum(long int a,long int b,long int st,long int et,long int i){
	if(a<=st&&b>=et)
		return s.at(i);
	else if(a>et||b<st)
		return 0;
	else
	{
		long int mid=(st+et)/2;
		return getSum(a,b,st,mid,i*2+1)+getSum(a,b,mid+1,et,i*2+2);
	}
}
void updateTree(long int diff,long int pos,long int st,long int et,long int i){
	if(pos<st||pos>et)
		return;

	s.at(i)+=diff;
	if(st!=et){
		long int mid=(st+et)/2;
		updateTree(diff,pos,st,mid,i*2+1);
		updateTree(diff,pos,mid+1,et,i*2+2);
	}
}
int main(){
	
	vector<long  int> v;
	long int diff;
	long int t;
	long int temp;
	long int no;
	long int pos,val,p,q;
	long int a,b,com;
	
	long int n,c;
	t=read_int();
	while(t--){
		n=read_int();
		c=read_int();
		for(long int i=0;i<n;i++){
			v.push_back(0);
		}
		long int size=2*(long int)(pow(2,((long int)ceil(log2(v.size())))))-1;
		s.resize(size);
		buildSegTree(0,v.size()-1,v,0);
		for(long int i=0;i<c;i++){
			com=read_int();
			switch(com){
				case 0:
				{
					p=read_int();
					q=read_int();
					val=read_int();
					p--;q--;
					for(long int j=p;j<=q;j++){
						updateTree(val,j,0,v.size()-1,0);
					}
				}
				break;
				case 1:
				{
					p=read_int();
					q=read_int();
					p--;q--;
					cout<<getSum(p,q,0,v.size()-1,0)<<endl;
				}
				break;
			}
		}
	}
	return 0;
}
