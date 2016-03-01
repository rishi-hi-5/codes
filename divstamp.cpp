#include<iostream>
#include<stdio.h>
using namespace std;
#define gc getchar_unlocked
int read_int() {
  char c;
	c=gc();
  while(c<'0' || c>'9') c = gc();
  int ret = 0;
  while(c>='0' && c<='9') {
    ret = 10 * ret + c - 48;
    c = gc();
  }
  return ret;
}
int main()
{
	long long int n,x=0,t;
	n=read_int();
	t=n;
	while(n--)
	{
		x+=read_int();
	}
	if((t*(t+1)/2)==x) cout<<"YES\n";
	else cout<<"NO\n";
	return 0;
}
