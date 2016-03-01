#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int t;
	long long int x;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld",&x);
		if(x%2==0)
		{
			printf("%lld\n",x);
		}			
		else
			printf("%lld\n",x-1);
	}
}
