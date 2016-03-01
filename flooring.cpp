#include<iostream>
#include<stdio.h>
using namespace std;
#define gc getchar_unlocked
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
	unsigned long long int t,n,m,i=1,ans;
	t=read_int();
	while(t--)
	{
		ans=0;
		n=read_int();
		m=read_int();
		while(i<=n)
		{
			ans+=(i*i*i*i)*(n/i);
			i++;
		}
		cout<<ans%m<<"\n";
	}
	return 0;
}
