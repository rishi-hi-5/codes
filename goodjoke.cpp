#include<iostream>
using namespace std;
#include<stdio.h>
int main()
{
	int t,n,i,temp,xx;
	cin>>t;
	while(t--)
	{	
		temp=0;
		cin>>n;
		for(i=0;i<2*n;i++)
		{
			cin>>xx;
		}
		for(i=1;i<=n;i++)
		{
			temp=temp^i;
		}	
		cout<<temp<<"\n";	
	}
	return 0;
}
