#include<stdio.h>
//#include<conio>
int main()
{

	int t,error,flag=0;
	char ch;
	scanf("%d",&t);
	ch=getchar();
	while(t--)
	{
	//	printf("%d",flag);
		error=0;
		/*if(flag==0)
		{
			ch=getchar();
			flag=1;
			break;
		}*/
		ch=getchar();
	//	printf("%c",ch);
		while(ch>='0'&&ch<='9')
		{
	//		printf("%c",ch);
			if(ch!='7'&&ch!='4')
			error++;
			ch=getchar();
		//	ch=getchar();
		}
		printf("%d\n",error);
	}
	
return 0;	
}
