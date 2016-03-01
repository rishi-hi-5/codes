#include<cstdio>
#include<iostream>
#include<bitset>
#include<cmath>
#define gc getchar_unlocked 
using namespace std;
string str;
unsigned long long int read_int()
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
string binary(unsigned long long int number) {
	int remainder;
	if(number <= 1) {
		str+=((char)number+'0');
		return str;
	}

	remainder = number%2;
	binary(number >> 1);    
	str+=((char)remainder+'0');
}

 
int main()
{
	int t,c;
	unsigned long long int x,inc,dec,i,len1,len2;
	string a,b,temp,sum;
	t=read_int();
	while(t--)
	{	
		str="";
		dec=0;
		c=0;
		cin>>a;
		temp="";
		inc=read_int();
		len1=a.length();
		b=binary(inc);
		len2=b.length();
		for(i=0;i<len1-len2;i++)
		{
			temp+='0';	
		}
		b=temp+b;
		
		for(i = 0; i < len1 ; i++)	
		{
			   cout<<((((int)a[i]-48) ^((int)b[i]-48)) ^ c); 
			   c =((((int)a[i]-48) &((int)b[i]-48)) | (((int)a[i]-48) & c)) | (((int)b[i]-48) & c); 
  			   c =((((int)a[i]-48) &((int)b[i]-48))); 
		}
		printf("\n");
	}
	return 0;
}
