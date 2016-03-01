#include<stdio.h>
#include<iostream>
#include<cmath>
#define gc getchar_unlocked
#define pc putchar_unlocked
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
	unsigned long long int n,m,q,r,t,i,f1,f2,f3,ans;
	t=read_int();
	while(t--)
	{
		n=read_int();
		m=read_int();
		r=read_int();
		while(r--)
		{
			q=read_int();
			f1=1;f2=1;f3=1;
			for(i=2;i<=n;i++)
			{
				f1*=pow(i,i);
			}
			
			for(i=2;i<=n-q;i++)
			{
				f2*=pow(i,i);
			}
			for(i=2;i<=q;i++)
			{
				f3*=pow(i,i);
			}
			ans=(f1*1.0)/(f2*f3);

			cout<<(ans%m)<<"\n";
		}
	}
	return 0;
}
