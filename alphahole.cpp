#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;
int main()
{
int T,cnt,i=0;
char c;
string s;
scanf("%d",&T);
	while(T--)
	{
	  cnt=i=0;
	  cin>>s;
	
c=s[i];
	  while(c!='\0')
	  {
		c=s[i];
		if(c=='A'||c=='B'||c=='D'||c=='O'||c=='P'||c=='Q'||c=='R')
		{
		if(c=='B')
		cnt+=2;
		else
		cnt+=1;		
		}
		i++;
	  }
	printf("%d\n",cnt);
	
	}
return 0;

}
