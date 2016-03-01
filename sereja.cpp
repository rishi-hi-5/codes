#include<iostream>
#include<stdio.h>
#define gc getchar_unlocked
using namespace std;
int read_int()
{
	char ch;
	ch=gc();
	while(ch<'0'||ch>'9') ch=gc();
	int ret =0;
	while(ch>='0'&&ch<='9')
	{
		ret=ret*10+ch-48;
		ch=gc();
	}
	return ret;
}
int main()
{
	int t,n,b;
	long int sum;
	t=read_int();
	while(t--)
	{	sum=0;
		n=read_int();
		while(n--)
		{
			b=read_int();
			sum+=b;			
		}	
		if(sum==100||sum==101)
		cout<<"YES\n";
		else
		cout<<"NO\n";
	}
	return 0;
}
