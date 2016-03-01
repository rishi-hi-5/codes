
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * **
* Author : Prasad J Ghangal					*
* Title :  				*
* Category : 						*
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include <stdio.h>
#include <string.h>

int main()
{
	char a[110],b[300];
	int l,i,flag,j,flag1;
	while(scanf("%s",a)!=EOF)
	{
		if(a[0]<='Z' && a[0]>='A')
			printf("Error!\n");
		else
		{
			flag=flag1=0;
			j=0;
			l=strlen(a);
			if(a[0]!='_')
			{
				b[j]=a[0];
				j++;
			}
			else{
				flag=1;
				flag1=1;
			}
			if(a[l-1]=='_')
				flag=1;
			for(i=1;i<l;i++)
			{
				if(a[i-1]=='_')
				{
					flag1=1;
					if(a[i]=='_' || (a[i]<='Z' && a[i]>='A') || flag1==2)
					{
						flag=1;
						break;
					}
				//	if(i==1)
				//		b[j]=a[i];
				//	else
						b[j]=a[i]-32;
					j++;
				}
				else if(a[i]>='A' && a[i]<='Z')
				{
					if(flag1==1)
					{
						flag=1;
						break;
					}
					else
						flag1=2;
					b[j]='_';j++;
					b[j]=a[i]+32;j++;
					//printf("_%c",a[i]+32);
				}
				else if(a[i]!='_')
				{
					b[j]=a[i];j++;
				}
				else{
					if(flag1==2)
					{
						flag=1;
						break;
					}
					flag1=1;
				}

			}
			b[j]='\0';
			if(flag==1)
				printf("Error!\n");
			else
				printf("%s\n",b);
		}
	}
	return 0;
}
