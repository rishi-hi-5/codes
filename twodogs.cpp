#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;
#define gc getchar_unlocked
long long int read_int()
{
	char ch;
	ch=gc();
	while(ch<'0'||ch>'9') ch=gc();
	long long int ret=0;
	while(ch>='0'&&ch<='9')
	{
		ret=ret*10+ch-48;
		ch=gc();
	}
	return ret;
}
int main()
{
	long long int n,k,i,j,sum,r,flag=0;
	n=read_int();
	k=read_int();
	vector <int> v(n);
	for(i=0;i<n;i++)
	{
		v.at(i)=read_int();
	}
	i=0;j=n-1;
	r=i+1;
	while(i>=j)
	{
		if(k==(v.at(i)+v.at(j)))
		{
			cout<<r<<"\n";
			flag=1;
			break;
		}
		i++;j--;r++;	
	}
	if(i==j)
	{
		if(k==v.at(i))
		{
			cout<<r<<"\n";
			flag=1;
		}
	}
	if(flag==0)
	cout<<"-1\n";
	return 0;
}
