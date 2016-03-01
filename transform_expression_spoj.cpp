#include<iostream>
#include<cstdio>
#include<stack>
#include<cctype>
#include<cstdlib>
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
int precedence(char ch)
{
	switch(ch)
	{
		
		case '(':
		case '^':
			return 0;
		case '+':
		case '-':
			return 1;
		case '*':
		case '/':
			return 2;
	}
}

int main()
{
	char ch;
	int flag=0,t;
	string str;
	stack<char> st;
	t=read_int();
	cin.clear();
	while(t--)
	{
		str="";
	while(1)
	{
		ch=getchar();
		if(ch=='\n')
		break;
		if(isalpha(ch))
		{
			str+=ch;	
		}
		else
		{
			if(st.empty())
				st.push(ch);
			else
			{
				if(ch==')')
				{
					char x=st.top();
					while(x!='(')
					{
						str+=x;
						st.pop();
						 x=st.top();
					}
						st.pop();	
				}
				else if(precedence(ch)>=precedence(st.top())||ch=='(')
					st.push(ch);
				else
				{
					while(precedence(ch)<precedence(st.top())&&!st.empty()||st.top()!='(')
					{
						str+=st.top();
						st.pop();
					}
					st.push(ch);
				}
				
			}	
		}
	}
	while(!st.empty())
	{
		str+=st.top();
		st.pop();
	}
	cout<<str<<"\n";
	}
	return 0;
}
