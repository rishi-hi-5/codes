#include<iostream>
#include<cstdio>
using namespace std;

unsigned long long int no;
bool ispalin(int nn)
{
	int temp,res=0,org;
	temp=nn;
	org=nn;
	while(nn!=0)
	{
		temp=nn%10;
		nn=nn/10;
		res=res*10+temp;
	}
	if(org==res)
		return true;
	else return false;		
}

int main()
{
	int t;
	cin>>t;
	int i;
	while(t--)
	{
		cin>>no;
		no=no+1;
		for(i=no;!ispalin(i);i++);
		cout<<i<<endl;
	}
}
