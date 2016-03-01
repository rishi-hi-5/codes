#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	float init,left;
	int withdraw;

	cin>>withdraw;
	cin>>init;

	if(withdraw+0.5>init)
	{
		printf("%.2f\n",init);
	}

	else
	{ 
		if(withdraw%5==0)
		{
			left=init - withdraw - 0.50;
			printf("%.2f\n",left);
		}
		else
			printf("%.2f\n",init);
	}
	return 0;
}
