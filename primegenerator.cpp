#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstdlib>
#include<cstring>
using namespace std;
#define gc getchar_unlocked
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
int *b;
int sieve(int e)
{
	int size=sqrt(e);
	b=(int*)malloc(sizeof(int)*size);
	memset(b,'0',sizeof(b));
	for(int i=2;i<size;i++)
	{
		if(b[i]==0)
			b[i]++;
		else
		for(int j=i;j<size;j+=i)
		{
			b[j]=1;		
		}
	}
}
int main()
{
	int t;
	int *a;
	int s,e;
	e=read_int();
//	while(t--)
//	{
//		a=new int[e-s];
		s=sieve(e);	
//	}
	for(int i=0;i<s;i++)
	{
		cout<<b[i];
	}
}
