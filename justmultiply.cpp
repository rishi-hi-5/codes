#include<cstdio>
#include<iostream>
#include<cmath>
#define gc getchar_unlocked
using namespace std;
unsigned long long int read_int()
{
	char ch;
	ch=gc();
	while(ch<'0'||ch>'9') ch=gc();
	unsigned long long int ret=0;
	while(ch>='0'&& ch<='9')
	{
		ret=ret*10+ch-48;
		ch=gc();
	}
	return ret;
} 
int main()
{
	unsigned long long int m,mul,t,x,y;
	int flag=0;
	char ch='v';
	t=read_int();
	while(t--)
	{
		mul=1;
		m=read_int();
		while(true)
		{
			x=read_int();
			y=read_int();		
			mul*=pow(x,y);
			fflush(stdin);
			ch=gc();
			if(ch=='\n')
			break;
		}
		printf("%llu\n",(mul%m));
	
	}
}
