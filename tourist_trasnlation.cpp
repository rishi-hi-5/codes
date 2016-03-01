#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	string str1,str2,str3,res;//str1 for small string,str2 for big string and str3 for query string
	int t;
	char ch;
	scanf("%d",&t);
	cin>>str2;
	str1=str2;
	transform(str2.begin(), str2.end(),str2.begin(),::toupper);
	while(t--)
	{
		res="";
		cin>>str3;
		for(int i=0;i<str3.length();i++)
		{
			if(str3[i]>='a'&&str3[i]<='z')
			{
				ch=str1[((int)str3[i]-'a')];
			}
			else if(str3[i]>='A'&&str3[i]<='Z')
			{
				ch=str2[((int)str3[i]-'A')];
			}
			else if(str3[i]=='_')
			{
				ch=' ';
			}
			else
			{
				ch=str3[i];
			}
			res+=ch;
		}	
		cout<<res<<"\n";
	}
	return 0;
}
