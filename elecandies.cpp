#include<iostream>
#include<stdio.h>
#define gc getchar_unlocked
using namespace std;
unsigned long long int read_int()
{
	char ch;
	ch=gc();
	while(ch<'0'||ch>'9') ch=gc();
	unsigned long long int ret=0;
	while(ch>='0'&&ch<='9')
	{
		ret=ret*10+ch-48;
		ch=gc();
	}
	return ret;
}
int main()
{
	unsigned long long int c,n,i,ans=0,t;
	t=read_int();
	while(t--)
	{	ans=0;
		n=read_int();
		c=read_int();
		for(i=0;i<n;i++)
		{
			ans+=read_int();
		}
		if(ans<=c)
		cout<<"Yes\n";
		else
		cout<<"No\n";
	}
	return 0;
}

