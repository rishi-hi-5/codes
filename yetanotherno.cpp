#include<stdio.h>
#include<iostream>
#define gc getchar_unlocked
using namespace std;
long long int read_int()
{
	char ch;
	ch=gc();
	while(ch<'0'||ch>'9') ch=gc();
	long long int ret =0;
	while(ch>='0'&&ch<='9')
	{
		ret=ret*10+ch-48;
		ch=gc();
	}
	return ret;
}
int main()
{
	int t;
	long long int n;
	t=read_int();
	while(t--)
	{
		n=read_int();
		if(n%2==0)cout<<"ALICE\n"; else cout<<"BOB\n";
	}
	return 0;
}
