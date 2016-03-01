#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
#define gc getchar_unlocked
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
int main()
{
	long int t,n,x,cnt,i,max=0,k,a[1000];
	t=read_int();
	while(t--)
	{
		max=0;
		cnt=0;
		n=read_int();
		memset(a,0,sizeof(long int)*1000);
		for(i=0;i<n;i++)
		{
			x=read_int();
			a[x]++;	
		}
		for(i=0;i<1000;i++)
		{
			if(max<a[i])
			{
				max=a[i];
				k=i;
			}
		}
		for(i=0;i<1000;i++)
		{
			if(i==k)
			continue;
			else
			{
				cnt+=a[i];
			}
		}
		cout<<cnt<<"\n";
	}
	return 0;
} 
