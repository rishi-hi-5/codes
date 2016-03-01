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
	int t,x11,x21,y11,y21,x12,y12,x22,y22,a,b,c,d,f;
	long long int a1,a2,a3;
	t=read_int();
	while(t--)
	{
		x11=read_int();			
		y11=read_int();
		x21=read_int();
		y21=read_int();
		a1=(x21-x11)*(y21-y11);
		x12=read_int();			
		y12=read_int();
		x22=read_int();
		y22=read_int();
		a2=(x22-x12)*(y22-y12);
		
			if(x12<x11)
			a=x11;
			else
			a=x12;
			if(x22<x21)
			c=x22;
			else
			c=x21;
			if(y12>y11)
			b=y12;
			else
			b=y11;
			if(y22>y21)
			d=y21;
			else
			d=y22;
			if(a==x12&&b==y12&&c==x21&&d==y22)
			cout<<(a1+a2)<<"\n";
			else
			{
				a3=(c-a)*(d-b);
				cout<<(a1+a2-a3)<<"\n";
			}
	}
	return 0;
}

