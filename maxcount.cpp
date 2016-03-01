#include<iostream>
#include<stdio.h>
#include<malloc.h>
#define gc getchar_unlocked
using namespace std;
int read_int()
{
	char ch;
	while(ch<'0'||ch>'9')ch=gc();
	int ret=0;
	while(ch>='0'&&ch<='9')
	{
		ret=ret*10+ch-48;
		ch=gc();
	}
	return ret;
}

struct link
{
	long int a;
	long int s;
	struct link* next;
}*head;
void maxse()
{
	struct link*gotit;
	int m1=0,m2=0;
	for(gotit=head;gotit->next!=0;gotit=gotit->next)
	{
		if(m2<gotit->s)
		{
			m1=gotit->a;
			m2=gotit->s;
		}
	}
	cout<<m1<<" "<<m2;
}	
int search(long int v)
{
	struct link * se;
	if(head==0)
	{
		return -1;
	}
	else
	{
		for(se=head;se->next!=0;se=se->next)
		{
			if(se->a==v)
			{
				se->s++;
				break;
			}
		}
	}
}
void create(long int v)
{
	static struct link*start=0,*node=0;
	if(start==0)
	{
		start=(struct link*)malloc(sizeof(struct link));
		start->a=v;
		start->s++;
		start->next=0;
		head=start;
	}
	else
	{
		node=(struct link*)malloc(sizeof(struct link));
		node->a=v;
		node->s++;
		node->next=0;
		start->next=node;
		start=start->next;
	}
	
}
int main()
{
	int t,p;
	long int n,v;
	t=read_int();
	while(t!=0)
	{
		n=read_int();
		for(int i=0;i<n;i++)
		{
			v=read_int();
			p=search(v);
			if(p==-1)
			create(v);
		}
		maxse();
		cout<<"\n";
		free(head);
		t--;
	}
	return 0;
}
