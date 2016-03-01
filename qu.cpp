#include<iostream>
#include<stdio.h>
#define gc getchar_unlocked
using namespace std;
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
	long long int n,t,m,i,j,s,e,max,min,max_e,count;
	char c;
	
	n=read_int();
	m=read_int();
	long long int a[n];
	for(t=0;t<n;t++)
	{
		a[t]=read_int();
	}	
	while(m)
	{
		c=gc();
		if(c=='Q')
		{
			m-=1;
			s=read_int();
			scanf("%lld",&e);
			min=a[s-1]-e;
			max=a[s-1]+e;
			max_e=a[s-1];
			i=s;
			count=1;
			if(a[s-1]<min)
				cout<<"-1 -1"<<"\n";
			else
			{
				while(1)
				{
					if((a[i]<=max) && (a[i]>=min))
					{
						count++;
						if(max_e<a[i])
							max_e=a[i];
					}
					else
						break;
					i++;
				}
				cout<<count<<" "<<max_e-a[s-1]<<"\n";
			}
		}
		else if(c=='U')
		{
			m-=1;
			s=read_int();
			e=read_int();
			a[s-1]=e;
		}
	}
	return 0;
}
