#include<iostream>
#include<stdio.h>
#define gc getchar_unlocked
using namespace std;
int read_int()
{
	char ch;
	ch=gc();
	while(ch<'0'||ch>'9') ch=gc();
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
	int t,n;
	long int i,j,cnt=0,fl=0;
	char ch;
	t=read_int();
	while(t--)
	{	j=1;
		fl=0;
		n=read_int();
		for(i=0;i<n*n;i++)
		{
			cin>>ch;
			if(ch=='#')
			{
				cnt=0;
			}
			else if(ch=='.')
			{
				cnt++;
			}
			if((i+1)==j*n)
			{
				j++;
				fl+=cnt;
				cnt=0;
			}
			cin.clear();
		}
		cout<<fl<<"\n";
	}
	return 0;
}
