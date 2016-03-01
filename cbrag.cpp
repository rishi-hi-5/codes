/*
Author : Rushikesh M fanse
problem	: chef and memory limits
*/
#include<cstdio>
#include<iostream>

using namespace std;

int main()
{
	int n,t,actual_allo,ans_allo,temp;//actual memory allocation and deallocation , in answer we take in consideration of the total memory ever allocated
	scanf("%d",&t);
	while(t--)
	{	
		actual_allo=0;
		ans_allo=0;
		scanf("%d",&n);
		while(n--)
		{
			scanf("%d",&temp);
			if(actual_allo<temp)
			{
				ans_allo+=(temp-actual_allo);
				actual_allo+=(temp-actual_allo);
			}
			else
				actual_allo+=(temp-actual_allo);
		}
		printf("%d\n",ans_allo);
	}
}
