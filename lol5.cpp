#include<iostream>
#include<stdio.h>
using namespace std;
struct stack
{
	long long int node;
	long long int left;
	long long int right;
}s;
int main()
{
	int t=0;
	char ch;
	
	//stack s;
	s.node=1;
	s.left=2;
	s.right=4;
	cin>>t;
	while(t!=0)
	{
		s.node=1;
        	s.left=2;
       		s.right=4;
		ch=getchar_unlocked();
	//	cin>>ch;
		while(true)
		{
			if(ch=='l')
			{
				if(s.node%2==0)
				{
					s.node=s.left;
					s.left=s.node*2;
					s.right=s.left+2;
				}
				else if(s.node%2==1)
				{
					s.node=s.left;
					s.left=2*s.node-1;
					s.right=s.left+2;
				}
			}
			if(ch=='r')
			{
				if(s.node%2==0)
				{
					s.node=s.right;
					s.left=s.node*2;
					s.right=s.left+2;
				}
				else if(s.node%2==1)
				{
					s.node=s.right;
					s.left=2*s.node-1;
					s.right=s.left+2;
				}
			}
			s.node=s.node%1000000007;
			ch=getchar_unlocked();
		//	cout<<s.node;
		//	cin>>ch;
			if(ch=='\n')
			break;
		}
	//s.node=s.node%1000000007;
	cout<<s.node;
	cout<<"\n";	
		t--;
	}
	return 0;
}
