#include<stdio.h>

int  main()
{
	int n;
	long unsigned int k,i=0,l,c=0;
	scanf("%d %lu",&n,&k);
	while(n!=0)
	{
		scanf("%lu",&l);
		if(l%k==0)
		c++;
		n--;	
	}
	printf("%lu",c);
return 0;
}
