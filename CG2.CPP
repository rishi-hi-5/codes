#include<stdio.h>
#include<graphics.h>

void polyfill(int a[][2],int size)
{
	float b[10][5],temp;
	int i,j;
	for(i=0;i<size-1;i++)
	{
		b[i][0]=a[i][0];
		b[i][1]=a[i][1];
		b[i][2]=a[i+1][0];
		b[i][3]=a[i+1][1];
		b[i][4]=float((a[i+1][1]-a[i][1]))/(a[i+1][0]-a[i][0]);
	}
		b[i][0]=a[i][0];
		b[i][1]=a[i][1];
		b[i][2]=a[0][0];
		b[i][3]=a[0][1];
		b[i][4]=float((a[0][1]-a[i][1]))/(a[0][0]-a[i][0]);
		for(i=0;i<size;i++)
		{
			for(j=i+1;j<size;j++)
			{
				if(b[0][i]<=b[0][j])
				{
					temp=b[0][j];
					b[0][j]=b[0][i];
					b[0][i]=temp;
				}
			}
		}

		for(i=0;i<10;i++)
		{
			for(j=0;j<5;j++)
			{
				printf(" %d %d %d %d %d ",b[i][0],b[i][1],b[i][2],b[i][3],b[i][4]);
			}
		}


}

void main()
{
	int gd,gm,x,a[10][2],i;
	gd=DETECT;

	printf("enter the no of edges in polygon");
	scanf("%d",&x);
	for (i=0;i<x;i++)
	{
		printf("enter the %d vertex",i);
		scanf("%d %d",&a[i][0],&a[i][1]);
	}
	initgraph(&gd,&gm,"c:\\turboC3\\bgi");
	for(i=0;i<x-1;i++)
	{
		line(a[i][0],a[i][1],a[i+1][0],a[i+1][1]);
	}
	line(a[i][0],a[i][1],a[0][0],a[0][1]);
       //	closegraph();
	polyfill(a,x);
}
