#include<iostream>
#include<cstdio>
using namespace std;
char* abc()
{
	char a[5];
	a[0]=a[1]=a[2]=a[3]=a[4]='a';
	return a;
}
int main()
{
	char b[5];
	*b=abc();
	printf("function returned array is \n");
	for(int i=0;i<5;i++)
	{
			cout<<b[i]<<endl;
	}
	return 0;
}