#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;
int a[26];
int main()
{
	string s="";
	char ch,res,f=0;
	int t,max,i;
	cin>>t;
	while(t--)
	{
		max=0;
		cin>>s;
		for(i=0;i<s.size();i++)
		{
			a[s[i]-97]++;
		}
		for(i=0;i<26;i++)
		{
			if(max<a[i]) 
			{
				max=a[i];
				res=i+97;
			}
		}
		for(i=0;i<s.size();i++)
		{
			if(s[i]==res)
			s[i]='?';
		}
		cout<<s<<"\n";
	}
	return 0;
}
