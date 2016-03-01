#include <string>
#include<iostream>
#include<cstdio>
using namespace std;
int ans,flag=0;
#define gc getchar_unlocked
long long int read_int()
{
	char ch;
	ch=gc();
	while(ch<'0'||ch>'9') ch=gc();
	long long int ret=0;
	while(ch>='0'&&ch<='9')
	{
		if(flag==0)
		{
			ans=ch-48;
			flag=1;
		}
		ret=ret*10+ch-48;
		ch=gc();
	}
	return ret;
}

int main()
{
	int t,temp;
	scanf("%d",&t);
	while(t--)
	{
		temp=read_int();
		flag=0;
		if(ans%2==0)
			cout<<"EVEN\n";
		else
			cout<<"ODD\n";
	}
	return 0;
}

