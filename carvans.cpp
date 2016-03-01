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
	while(ch>='0'&& ch<='9')
	{
		ret=ret*10+ch-48;
		ch=gc();
	}
	return ret;
} 
int main()
{
	int t;
	long int n,x,max,count=1;
	t=read_int();
	while(t--)
	{
		count=1;
		n=read_int();		
		x=read_int();
		max=x;
		while(--n)
		{
			x=read_int();
			if(x<max)
			{
				count++;
				max=x;
			}

		}
	
			cout<<count<<"\n";			
	}
	return 0;
}
