#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int t,x,y,k,n,p,c,flag;
	scanf("%d",&t);
	while(t--)
	{
		flag=0;
		scanf("%d",&x);//no of pages reuired for poetry
		scanf("%d",&y);//no of pages left	
		scanf("%d",&k);//money left for the book
		scanf("%d",&n);//no of notebooks
		while(n--)
		{
			scanf("%d",&p);
			scanf("%d",&c);
			if(p>=(x-y)&&c<=k)
				flag=1;
		
		}
		if(flag==1)
		printf("LuckyChef\n");
		else
		printf("UnluckyChef\n");
	}
	return 0;
}
