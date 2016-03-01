#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
using namespace std;
#define gc getchar_unlocked
#define MAX 100
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
char mat[MAX][MAX];
string str="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int k=0;
int r,c;
bool backtrack(int matvis[][MAX],int i,int j)
{
	matvis[i][j]=1;

	if(mat[i][j]==str[k])
	{
		k++;
		if(k==10)
			return true;
	}
	else
	{
		matvis[i][j]=0;
		return false;	
	}
	
	if(i+1<r&&i+1>=0&&matvis[i+1][j]!=1)
		backtrack(matvis,i+1,j);
	if(i-1<r&&i-1>=0&&matvis[i-1][j]!=1)
		backtrack(matvis,i-1,j);
	if(j+1<c&&j+1>=0&&matvis[i][j+1]!=1)
		backtrack(matvis,i,j+1);
	if(j-1<c&&j-1>=0&&matvis[i][j-1]!=1)
		backtrack(matvis,i,j-1);
	
	if(i+1<r&&i+1>=0&&j+1<c&&j+1>=0&&matvis[i+1][j+1]!=1)
		backtrack(matvis,i+1,j+1);

	if(i-1<r&&i-1>=0&&j+1<c&&j+1>=0&&matvis[i-1][j+1]!=1)
		backtrack(matvis,i-1,j+1);

	if(i-1<r&&i-1>=0&&j-1<c&&j-1>=0&&matvis[i-1][j-1]!=1)
		backtrack(matvis,i-1,j-1);

	if(i+1<r&&i+1>=0&&j-1<c&&j-1>=0&&matvis[i+1][j-1]!=1)
		backtrack(matvis,i+1,j-1);
	if(k==10)
	return true;
	k--;
	matvis[i][j]=0;
	return false;

}
int main()
{
	int t;
	int flag=0;
	int matvis[MAX][MAX];
	t=read_int();
	while(t--)
	{	
		flag=0;
		memset(mat,'0',sizeof(mat));
		memset(matvis,0,sizeof(matvis));
		r=read_int();
		c=read_int();
		for(int i=0;i<r;i++)
		for(int j=0;j<c;j++)
			cin>>mat[i][j];	
		for(int i=0;i<r;i++)
		{
		for(int j=0;j<c;j++)
		{
			k=0;
			if(backtrack(matvis,i,j))
			{
			
		
				matvis[i][j]=1;
				cout<<"YES\n";
				flag=1;	
				break;	
			}
			
		}
		if(flag==1)
				break;	
		}
		if(flag==0)
			cout<<"NO\n";
	}	
}
