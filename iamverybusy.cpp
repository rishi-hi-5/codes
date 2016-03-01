#include<iostream>
#include<cstdio>
#include<climits>
using namespace std;
int min_n=INT_MAX;
int main()
{
	int t,l,m,n,max_n=0,cnt,e;
		
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&l);
		int a[l][2];
		i=0;
		cnt=1;
		while(l--)
		{
			scanf("%d",&m);
			scanf("%d",&n);
			a[i][0]=m;
			a[i][1]=n;
			i++;
			if(max_n<n)
			{
				max_n=n;
			}
			if(min_n>n)
			{
				min_n=n;
			}
		}
		e=max_n;
		while(min_n!=max_n)
		{
				if(a[i][1]>min_n)
				{
					if(a[i][1]>e)
					{
						e=a[i][1];
					}
				}
		}
		
	}
	return 0;
}
