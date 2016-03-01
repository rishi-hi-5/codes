#include<stdio.h>
#include<string>
#include<iostream>
#include<stdlib.h>
using namespace std;
int main()
{
	int q;
	string s="",res="abcas";
	cout<<res.substr(0,2);
	char ch;
	scanf("%d",&q);
	while(q!=0)
	{
		std::getline (std::cin,s);
		//printf("www\n");
		if('+'==s[0])
		{
			printf("hello world\n");
			res=res.substr(0,(int)s[2]);//+s.substr(3,s.length())+res.substr(((int)s[2])+1,res.length());
		
		}
		else if('?'==s[0])
		{
			printf("%d",((int)s[2])-48);	
			cout<<res.substr(((int)s[2])-48,((int)s[4])-48);
		}
		s="";
		q--;
	}
return 0;
}



