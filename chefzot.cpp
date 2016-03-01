#include<iostream>
#include<stdio.h>
#define gc getchar_unlocked
using namespace std;
long int read_int()
{
	char ch;
	ch=gc();
	while(ch<'0'||ch>'9')ch=gc();
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
	long int n,a,max=0,count=0;
	n=read_int();
	while(n--)
	{
		a=read_int();
		if(a==0)
		{


			count=0;
		}
		else
		{
			count++;
		}
		
			if(max<count)		
			max=count;
	}
	cout<<max; 
	return 0;
}
