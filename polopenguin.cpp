#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int main()
{
	int t,z;
	unsigned long long l,r,res,u,v,i,len,kk;
	char buf[1];
	cin>>t;
	while(t--)
	{
		res=0;
		i=1;
		scanf("%llu",&l);
		scanf("%llu",&r);
		u=l;
		while(u<=r)
		{
			z=t;
			len=sprintf(buf,"%llu",u);
			t=z;
			v=min((unsigned long long)pow(10,len)-1,r);
			res+=len*(u+v)*(v-u+1)/2;
			u=v+1;
		}
		
		printf("%llu\n",res%((unsigned long long)pow(10,9)+7));	
	}
	return 0;
}
