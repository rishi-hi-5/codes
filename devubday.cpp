#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string.h>
using namespace std;
int main()
{
	int t,n,cnt,ele;
	int a[101];
	scanf("%d",&t);
	while(t--)
	{
		cnt=0;
		for(int i=0;i<101;i++)
			a[i]=1;
		scanf("%d",&n);
		while(n--)
		{
			scanf("%d",&ele);
			if(a[ele]==1)
			{
				cnt++;
				a[ele]--;
			}
		}
		printf("%d\n",cnt);
	}
}
