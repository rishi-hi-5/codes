#include<iostream>
#include<stdio.h>
#include<cmath>
#include<vector>
#define gc getchar_unlocked
using namespace std;
long int read_int()
{
	char ch;
	ch=gc();
	while(ch<'0'||ch>'9') ch=gc();
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
	long int t,x1,y1,x2,y2,x3,y3,cnt=0;
	int d1,d2,d3,max=0,max1,i;
	t=read_int();
	while(t--)
	{
		d1=d2=d3=0;
		max1=0;
		max=0;
		x1=read_int();
		y1=read_int();				
		x2=read_int();
		y2=read_int();
		x3=read_int();
		y3=read_int();
		d1=(x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
		d2=(x3-x2)*(x3-x2)+(y3-y2)*(y3-y2);
		d3=(x1-x3)*(x1-x3)+(y1-y3)*(y1-y3);
		if((d1==d2+d3) || (d2==d1+d3)||(d3==d1+d2))
			cnt++;
	}
	cout<<cnt<<"\n";
	return 0;
}
