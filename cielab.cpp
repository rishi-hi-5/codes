#include<iostream>
#include<stdio.h>
#define gc getchar_unlocked
using namespace std;
int read_int()
{
	char ch;
	while(ch<'0'||ch>'9')ch=gc();
	int ret=0;
	while(ch>='0'&&ch<='9')
	{
		ret=ret*10+ch-48;
		ch=gc();
	}
	return ret;
}
int main()
{
	int p;
	long int a,b,ans;
	a=read_int();
	b=read_int();
	ans=a-b;
	p=ans%10;
	if(p>5)
	cout<<(ans-1);
	else if(p<5)
	cout<<(ans+1);
	return 0;
}
