#include<stdio.h>
#include<string>
#include<iostream>
#include<stdlib.h>
using namespace std;
int main()
{
	int q;
	string s="",res="";

	char ch;
	scanf("%d",&q);
	q=q+1;
	while(q!=0)
	{
		std::getline (std::cin,s);
		//printf("www\n");
		if('+'==s[0])
		{
			puts((char*)res.substr(0,0));
			res=res.substr(0,((int)s[1])-48)+s.substr(3,s.length()-1)+res.substr(((int)s[1])-48+1,res.length()-1);
		
		}
		else if('?'==s[0])
		{
		//	printf("%d",((int)s[2])-48);	
			cout<<res.substr(((int)s[2])-48,((int)s[4])-48);
		}
		s="";
		q--;
	}
return 0;
}

