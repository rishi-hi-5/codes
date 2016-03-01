#include<stdio.h>
#include<malloc.h>
int main()
{
	long int n,q,cnt=0;//,a[100000];
	long int * a;
	int x0,x1,x2,i;
	scanf("%ld %ld",&n,&q);
	//a=(int*)malloc(sizeof(int)*n)
	while(q!=0)
	{
		 a=(long int*)malloc(sizeof(long int)*n);
		scanf("%d %d %d",&x0,&x1,&x2);
		if(x0==0)
		{
			for(i=x1;i<=x2;i++)
			{
				a[i]++;
			}
		}
		else
		{
			for(i=x1;i<=x2;i++)
			{
		//		printf("%ld",a[i]);
				if(a[i]%3==0)
				cnt++;	
			}
			
			printf("\n%ld\n",cnt);
			cnt=0;
		}
		free(a);
		q--;
	}
	
}
