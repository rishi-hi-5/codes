#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	int sum=0;
	int a[10]={6,2,5,5,4,5,6,4,7,6};
	string s;
	cin>>s;
	for(int i=0;i<s.length();i++)
	{
		sum+=a[(int)(s[i]-'0')];
	}
	cout<<sum<<"\n";
	return 0;
}
