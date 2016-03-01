#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#define gc getchar_unlocked
using namespace std;
long int read_int()
{
char ch;
ch=gc();
while(ch<'0'||ch>'9') ch=gc();
long int ret=0;
while(ch>='0'&&ch<='9')
{
ret=ret*10+ch-48;
ch=gc();
}
return ret;
}
int main()
{
vector<long int> v;
long int t,n,i,k,sum;
t=read_int();
while(t--)
{
n=read_int();
for(i=0;i<n;i++)
{
k=read_int();
v.push_back(k);
}
sort(v.begin(),v.end());
sum=v.at(0)+v.at(1);
cout<<sum<<"\n";
}
return 0;
}
