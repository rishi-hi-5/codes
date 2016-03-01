#include<iostream>
#include<cstdio>
#include<vector>
#define gc getchar_unlocked
using namespace std;
long int read_int()
{
	char ch;
	ch=gc();
	while(ch<'0'||ch>'9') ch=gc();
	long int ret=0;
	while(ch>='0'&& ch<='9')
	{
		ret=ret*10+ch-48;
		ch=gc();
	}
	return ret;
} 

int main()
{
	int t,x;
	vector<int> a(26);
	vector<int> b(20);
	t=read_int();
	for(int i=0;i<a.size();i++)
	{	
		x=gc();	
		a.at(i)=x;
	}


	return 0;
}
