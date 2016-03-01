#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int main()
{
	long int t,n,temp,cnt,cntb,i,m;
	vector<long int>v;
	scanf("%ld",&t);
	while(t--)
	{
		cnt=0;
		cntb=0;
		scanf("%ld",&n);
		m=n;
		for(i=0;i<n;i++)
		{
			scanf("%ld",&temp);
			v.push_back(temp);
		}
		for(i=0;i<m;i++)
		{
			
			if(i==0)
			{	
				if(v.at(i)!=v.at(i+1))
					cnt++;
				continue;
			}
			if(i==n-1)
			{
				if(v.at(i)!=v.at(i-1))
				{
					cnt++;
				}
				continue;
			}
			if(v.at(i)!=v.at(i+1)||v.at(i)!=v.at(i-1))
			{
				cnt++;
			}
		}
		cout<<cnt;
		cout<<"\n";
		v.clear();
	}
	return 0;
}
