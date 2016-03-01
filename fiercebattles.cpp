//author rushikesh fanse
//code for codechef problem fierce battles
#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<string.h>
using namespace std;
int main()
{
	int m,n,t,i,j,sum;
	long int a[101];//at max 100 levels would be there
	int lvl,val;
	scanf("%d",&t);
	while(t--)
	{
		sum=0;
		memset(a,0,sizeof(long int)*101);	
		scanf("%d",&m);
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d",&val);
			scanf("%d",&lvl);
			a[lvl]+=val;
		}
		for(i=0;i<m;i++)
		{
			scanf("%d",&val);
			scanf("%d",&lvl);
			a[lvl]-=val;
		}
		for(i=0;i<101;i++)
		{
			if(a[i]<0)
			{
				sum+=(0-a[i]);
			}
		}
		printf("%d\n",sum);
	}
	return 0;
}
