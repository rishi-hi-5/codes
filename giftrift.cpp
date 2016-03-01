#include<iostream>
#include<cstdio>
#include<cmath>
#define gc getchar_unlocked
using namespace std;
long int read_int()
{
	char ch;
	ch=gc();
	while(ch<'0'||ch>'9') ch=gc();
	long int ret=0;
	while(ch>='0'&& ch<='9')
	{
		ret=ret*10+ch-48;
		ch=gc();
	}
	return ret;
} 
int smalleler[100],smallelec[100];
int main()
{
	long int r,c,i,j,flag=0,min,max,k;
	r=read_int();
	c=read_int();
	k=pow(10,9);
	long int a[r][c];
	for(i=0;i<r;i++)
	{
		min=k;
		for(j=0;j<c;j++)
		{
			a[i][j]=read_int();
			if(min>a[i][j])
			{
				min=a[i][j];
			}
		}
		smalleler[i]=min;
	}
	for(j=0;j<c;j++)
	{
		max=0;
		for(i=0;i<r;i++)
		{
			if(max<a[i][j])
			{
				max=a[i][j];
			}	
		}
		smallelec[j]=max;
	}
	for(i=0;i<r;i++)
	{
	for(j=0;j<c;j++)
	{
		if(a[i][j]==smalleler[i])
		{
			if(a[i][j]==smallelec[j])
			{	
				cout<<a[i][j]<<endl;
				flag=1;
				break;
			}
		}
	
	}
		if(flag==1)
		break;
	}
	if(flag==0)
	printf("GUESS\n");

	return 0;
}
