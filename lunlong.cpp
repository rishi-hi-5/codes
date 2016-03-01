#include<stdio.h>
 
int main()
{
 
int t,error,flag=0;
char ch;
scanf("%d",&t);
ch=getchar();
while(t--)
{
error=0;
ch=getchar();
while(ch>='0'&&ch<='9')
{
if(ch!='7'&&ch!='4')
error++;
ch=getchar();
}
printf("%d\n",error);
}
return 0;
}
