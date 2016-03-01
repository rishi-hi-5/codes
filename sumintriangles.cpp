#include<cstdio>
#include<iostream>
#define gc getchar_unlocked
using namespace std;
long int maximum(long int a,long int b)
{
	if(a>b)
		return a;
	else
		return b;
}
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
int main()
{
	long int t,i,n,j,max,flag;
	t=read_int();
	while(t--)
	{
		max=0;
		flag=0;
		n=read_int();
		long int a[n+1][n+1];
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=i;j++)
			{
				scanf("%ld",&a[i][j]);
				if(n==1)
				{
					printf("%ld\n",a[i][j]);
					flag=1;
				}
				else if(i>=2)
				{
					if(j==1)
					{
						a[i][j]+=a[i-1][j];
					}
					else if(j==i)
					{
						a[i][j]+=a[i-1][j-1];
					}
					else
					{
						a[i][j]+=maximum(a[i-1][j-1],a[i-1][j]);
					}
				}
			}
		}
		if(flag==0)
		{
			for(i=1;i<=n;i++)
			{
				if(max<a[n][i])
				{
					max=a[n][i];
				}	
			}
			printf("%ld\n",max);
		}
	}
	return 0;
}
