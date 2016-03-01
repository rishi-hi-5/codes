#include<cstdio>
#include<iostream>
#include<list>
#include<cstring>
using namespace std;
int main()
{
	int t,cnt,l,flag;
	list<char> l1,l2;
	char ch,temp,remo;
	string str,res;
	scanf("%d",&t);
	while(t--)
	{
		res="";
		flag=0;
		cnt=0;
		cin>>l;
		cin>>str;
		for(int i=0;i<str.length();i++)
		{
			l1.push_back(str[i]);
		}
		l2=l1;
		l2.sort();
		for(list<char>::iterator i=l2.begin(),e=l2.end(),j=l1.begin();i!=e;i++,j++,cnt++)
		{
			if(*i==*j)
				continue;
			else
			{
				l1.insert(j,*i);
				j++;
				remo=*i;
				flag=1;
				break;
			}
		}
		if(flag==1)
		{
			cnt=0;
			for(list<char>::iterator j=l1.begin(),e=l1.end();j!=e;j++)
			{
				if(remo==*j)
				{
					cnt++;
				}
			}
		
			for(list<char>::iterator j=l1.begin(),e=l1.end();j!=e;j++)
			{
				if(remo==*j)
				{
					cnt--;
				}
				if(cnt==0)
				{
					cnt=99;
					continue;
				}
				res+=*j;	
			}
		cout<<res<<"\n";
		}
		else
		{
			cout<<str<<"\n";
		}
		l1.clear();
		l2.clear();
		
	}
	return 0;
}
