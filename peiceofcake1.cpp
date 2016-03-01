#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;
#define gc getchar_unlocked
int read_int()
{
	char ch;
	ch=gc();
	while(ch<'0'||ch>'9') ch=gc();
	int ret=0;
	while(ch>='0'&& ch<='9')
	{
		ret=ret*10+ch-48;
		ch=gc();
	}
	return ret;
} 
int main()
{
	int t,x1,y1;
	int a[26];
	char ch,x,y;
	t=read_int();
	while(t--)
	{
		x1=0;
		y1=0;
		ch=gc();
		x=ch;
		while(ch!='\n')
		{
			if(ch==x)
			x1++;
			else
			y1++;
			ch=gc();
		}
		if(x1==y1)
		printf("YES\n");
		else
		printf("NO\n");
	}
	return 0;
}
