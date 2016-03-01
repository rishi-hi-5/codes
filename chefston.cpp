#include<stdio.h>
#include<iostream>
#define gc getchar
int flag;
using namespace std;

int read_int() {
  char c = gc();
  while(c<'0' || c>'9') c = gc();
  int ret = 0;
  while(c>='0' && c<='9') {
    ret = 10 * ret + c - 48;
    c = gc();
  }
  if(c=='\n')
	flag=1;
  return ret;
}
int main()
{
	int t,ch;
	cin>>t;
	while(t--)
	{	
		while(flag!=1)
		{
			t=read_int();
			printf("%d",t);
		}
		flag=0;
	}
	return 0;
}
