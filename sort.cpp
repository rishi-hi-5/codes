#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	long int t,temp,n;
	vector<long int> v;
	scanf("%ld",&t);
	n=t;
	while(t--)
	{
		scanf("%ld",&temp);
		v.push_back(temp);	
	}
	sort(v.begin(),v.end());
	temp=0;
	while(n--)
	{
		printf("%ld\n",v.at(temp++));
	}	
	return 0;
}
