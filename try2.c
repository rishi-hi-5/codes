#include<stdio.h>
void fun(int * ptr)
{	
	--ptr;
	*ptr=5;
	
	printf("modification done\n");
}
int main()
{
	int i,a[]={1,2,3,4};
	fun(a+2);
	for(i=0;i<4;i++)
	printf("%d ",a[i]);
}
