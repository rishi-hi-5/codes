#include<sstream>
#include<iostream>
#include<string.h>
#include<string>
#include<fstream>
#include<string>
#include<cstdlib>
using namespace std;
int a[52];
int main()
{
	int max,counter;
	int t;
	char ch;
	scanf("%d",&t);
	while(t--)
	{
		counter=0;
		max=0;
		for(int i=0;i<52;i++)
		{
			a[i]=0;
		}
		while((ch<'a'||ch>'z')&&(ch<'A'||ch>'Z'))ch=getchar_unlocked();
		do{
			if(ch>='a'&&ch<='z')
			{
				a[ch-'a']++;
			}
			else if(ch>='A'&&ch<='Z')
			{
				a[ch-'A'+26]++;
			}
			counter++;
		}while((ch=getchar_unlocked())!='\n');
		for(int i=0;i<52;i++)
		{
			if(a[i]!=1)
			if(max<a[i])
			{
				max=a[i];
			}
			
		}
		printf("%d\n",(counter-(max)/2));
		
	}
	return 0;
}
