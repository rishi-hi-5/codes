#include<stdio.h>
#include<stdlib.h>
#include<bits/stdc++.h>
using namespace std;
//#include <bits/stdc++.h>
int main()
{
	long int n,i=0,j,temp,t;
	long int *a;
	scanf("%ld",&n);
	t=n;
	a=(long int*)malloc(sizeof(long int)*n);
	while(t--)
	{
		scanf("%ld",&a[i]);
		//printf("hello");
		i++;
	}
	std::sort(a,a+n);
	for(i=0;i<n;i++)
	printf("%ld\n",a[i]);
return 0;
}
