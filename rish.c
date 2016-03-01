#include<stdio.h>
int main()
{	
	int t,i,acc,m=10,a,res,x,y,z;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&acc);
		
		for(i=0;i<acc;i++)
		{
			scanf("%d",&a);
			if(i==0)
			{
				res=a;
			}
			else
			{
				x=res+a;
				y=res-a;
				z=res*a;
				if(x<y&&x<z)
				res=x;
				else if(y<z)
				res=y;
				else
				res=z;
			}
		}
		printf("%d\n",res);
	}
}
