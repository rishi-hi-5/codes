#include<stdio.h>
#include<string>
#include<stdlib.h>
using std::string;
int prime(int M)
{
int flag=0;
	for(int i=2;i<M;i++)
	{
		if(M%i==0)
		{
		flag=0;
		break;
		}
		else
		{
		flag=1;
		}
	return flag;
}
}
int main()
{
string N;
long long int M;
int flag1=0,flag2=0;
scanf("%s",N);
M=atoi(N);
M++;
N=itoa(M);
	while(flag1!=1&&flag2!=1)
	{
		if(N==string(N.rbegin(),N.rend()))
		{
			flag1=1;
			flag2=prime(M);
		}
	M=atoi(N);
	M++;
	N=itoa(M);
	}
printf("%s",N);
return 0;
}
