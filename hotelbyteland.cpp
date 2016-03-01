#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#define gc getchar_unlocked
using namespace std;
int read_int()
{
	char ch;
	ch=gc();
	while(ch<'0'||ch>'9') ch=gc();
	int ret=0;
	while(ch>='0'&& ch<='9')
	{
		ret=ret*10+ch-48;
		ch=gc();
	}
	return ret;
} 
int main()
{
	int t,n,temp,max,cnt;
	vector<int> a;
	vector<int> b;
	t=read_int();
	while(t--)
	{
		n=read_int();
		cnt=n;	
		for(int i=0;i<n;i++)
		{
			temp=read_int();
			a.push_back(temp);
		}
		for(int i=0;i<n;i++)
		{
			temp=read_int();
			b.push_back(temp);
		}
		max=*max_element(a.begin(),a.end());
		for(int i=0;i<b.size();i++)
		{
			if(b.at(i)<=max)
			{
				cnt--;
			}
		}
		printf("%d\n",cnt);
		a.clear();
		b.clear();
	}
	return 0;
}

