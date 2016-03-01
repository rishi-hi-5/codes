#include<iostream>
#include<cstdio>
#include<string.h>
#define i 1
#define j 2
#define k 3
#define gc getchar_unlocked
using namespace std;
long long int read_int()
{
	char ch;
	ch=gc();
	while(ch<'0'||ch>'9') ch=gc();
	long long int ret=0;
	while(ch>='0'&& ch<='9')
	{
		ret=ret*10+ch-48;
		ch=gc();
	}
	return ret;
} 
int main()
{
	//int a[4][4]={{1,1,2,3},{1,-1,3,-2},{2,-3,-1,1},{3,2,-1,-1}};
	long long int t,len,rep;
	string str;
	t=read_int();
	while(t--)
	{
		len=read_int();
		rep=read_int();
		
		i=0;
		
	}	
	return 0;
}
