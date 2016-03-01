#include<iostream>//one testcase going wrong
#include<cstdio>
#include<vector>
using namespace std;
vector<int> v;
int main()
{	
	int n,k,q,temp,pos,val;
	scanf("%d %d %d",&n,&k,&q);
	while(n--)
	{
		scanf("%d",&temp);
		v.push_back(temp);
	}
	while(q--)
	{
		scanf("%d",&val);
		pos=v.size()-k;
		printf("%d\n",v.at((pos+val)%v.size()));
	}
	return 0;
}
