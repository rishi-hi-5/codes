#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int t,sum1,sum2,temp,x;
	scanf("%d",&t);
	while(t--)
	{
		sum1=0;
		sum2=0;
		scanf("%d",&x);
		while(x--)
		{
			scanf("%d",&temp);
			sum1+=temp;
			scanf("%d",&temp);
			sum2+=temp;
		}
		if(sum1>sum2)
			cout<<"Sahil\n";
		else if(sum1==sum2)
			cout<<"Draw\n";
		else 
			cout<<"Rosesh\n";
	
	}
	return 0;
}
