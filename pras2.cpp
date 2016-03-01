#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <iostream>
#define gc getchar_unlocked
using namespace std;

char a[2010],b[2010];
int x[2050][2050];
int fin()
{
	int res=0;
	register char c=gc();
	while(c<'0' || c>'9')
		c=gc();
	while(c>='0' && c<='9')
	{
		res=res*10+(c-48);
		c=gc();
	}
	return res;
}

int dp()	
{
	int i,j;
	int len1=strlen(a),len2=strlen(b);
	memset(x,0,sizeof(x));
	for(i=0;i<=len1;i++)
		x[0][i]=i;
	for(i=0;i<=len2;i++)
		x[i][0]=i;

	for(i=1;i<=len2;i++)
		for(j=1;j<=len1;j++)
		{
			if(b[i-1]==a[j-1])
				x[i][j]=x[i-1][j-1];
			else
				x[i][j]=min(x[i-1][j]+1,min(x[i][j-1]+1,x[i-1][j-1]+1));
		}
//	for(i=0;i<=strlen(b);i++)
//	{
//		for(j=0;j<=strlen(a);j++)
//			printf("%d ",x[i][j]);
//		printf("\n");
//	}
	return x[len2][len1];


}

int main()
{
	int t;
	t=fin();
	while(t--)
	{
		scanf("%s",a);
		scanf("%s",b);

		printf("%d\n",dp());
	}
	return 0;
}