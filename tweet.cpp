#include<iostream>
#include<stdio.h>
#include<cstring>
#define gc getchar_unlocked
using namespace std;
int read_int()
{
	char ch;
	ch=gc();
	while(ch<'0'||ch>'9') ch=gc();
	int ret=0;
	while(ch>='0'&&ch<='9')
	{
		ret=ret*10+ch-48;
		ch=gc();
	}
	return ret;
}
int a[1001];
int main()
{
	string s;
	int n,k,count=0,x;
	n=read_int();
	k=read_int();
	while(k--)
	{
		cin>>s;
		if(s=="CLOSEALL")
		{
			count=0;
			memset(a,0,sizeof(a));
			cout<<count<<"\n";
			continue;
		}
		x=read_int();
		if(a[x]==0)
		{
			a[x]++;
			count++;
			cout<<count<<"\n";
		}
		else
		{
			a[x]--;
			count--;
			cout<<count<<"\n";
		}
	}

}
