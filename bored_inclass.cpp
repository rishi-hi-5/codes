#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int t,hh,mm,cnth,cntm;
	long long int sec;
	string s;
	scanf("%d",&t);
	while(t--)
	{
		cin>>s;
		hh=((int)(s[0]-'0'))*10+((int)(s[1]-'0'));	
		mm=((int)(s[2]-'0'))*10+((int)(s[3]-'0'));
		scanf("%lld",&sec);
		cntm=sec/60;
		cnth=sec/3600;
		hh+=cnth;
		mm+=cntm;
		cout<<hh<<" "<<mm;
	}
	return 0;
}
