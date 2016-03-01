#include<iostream>
#include<stdio.h>
using namespace std;
int merge(int a[5],p,k)
{
	int i,j;
	if(((k-p)==1)||(k-p)==2)
	{
		if(k-p==1)
		return a[p]
		else
		{
		

		}
	}
	
	else
	{
		i=k/2;
		j=k
		merge(a,0,i);
		merge(a,i,j);	
	}
}
int main()
{
	int a[5];
	printf("enter the array");
	for(i=0;i<5;i++)
	cin>>a[i];
	merge(a,0,5);
	
	
	return 0;
}

