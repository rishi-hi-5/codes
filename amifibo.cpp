#include<iostream>
#include<stdio.h>
#define gc getchar_unlocked
using namespace std;
long int read_int()
{
	char ch;
	ch=gc();
	while(ch<'0'||ch>'9') ch=gc();
	long int ret=0;
	while(ch>='0'&&ch<='9')
	{
		ret=ret*10+ch-48;
		ch=gc();
	}
	
	return ret;
}

int main()
{
	int t,flag=0;
	long int fib[1001],i=3,x;
	fib[1]=0;
	fib[2]=1;
	while(i!=1001)
	{	
		fib[i]=fib[i-1]+fib[i-2];
		i++;
	}
	t=read_int();
	while(t--)
	{
		flag=0;
		x=read_int();
		for(i=1;i<=1001;i++)
		{
			if(x==fib[i])
			{
				cout<<"YES\n";
				flag=1;
				break;
			}
		}
		if(flag==0)
		{
			cout<<"NO\n";
		}
	}
	return 0;
}


