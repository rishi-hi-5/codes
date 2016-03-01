#include<iostream>
using namespace std;
struct stack
{
	int node;
	int left;
	int right;
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
		cin>>ch;
		while(ch!='\n')
		{
			if(ch=='l')
			{
				if(s.node%2==1)
				{
					s.node=s.left;
					s.left=s.node*2;
					s.right=s.left+2;
				}
				else if(s.node%2==0)
				{
					s.node=s.left;
					s.left=2*s.node-1;
					s.right=s.left+2;
				}
			}
			if(ch=='r')
			{
				if(s.node%2==1)
				{
					s.node=s.right;
					s.left=s.node*2;
					s.right=s.left+2;
				}
				else if(s.node%2==0)
				{
					s.node=s.right;
					s.left=2*s.node-1;
					s.right=s.left+2;
				}
			}
			cout<<s.node;
		}
		
		t--;
	}
	return 0;
}
