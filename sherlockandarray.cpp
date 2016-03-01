#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
vector<int> v;
int main()
{
	int t,n,temp,i,j,left,right,flag,k;
	scanf("%d",&t);
	while(t--)
	{
		left=0;
		right=0;
		flag=0;
		scanf("%d",&n);
		k=n;
	
		flag==1;
		
		while(k--)
		{
			scanf("%d",&temp);
			v.push_back(temp);
		}
		if(n==1)
		flag=1;
		else
		{
		i=0;
		j=n-1;
		left=v.at(i);
		right=v.at(j);
		i++;j--;
		while(true)
		{
			 if((i-1)==(j+1))
			{
				if(left==right)
				{
					flag=1;
					break;
				}
				
			}
		//	else if((i+1==j)||(j+1==i))
		//	break;
			else if(left==right&&(((i+1)!=j)||(j+1!=i)))
			{
				
				left+=v.at(i);
				right+=v.at(j);
				i++;
				j--;
			}
			else if(i>j)
			break;		
			else if(left>right)
			{	
				right+=v.at(j);
				j--;
			}
			else if(left<right)
			{
				left+=v.at(i);
				i++;
			}
		
			else
			break;
		}
		}
		if(flag==1)
		cout<<"YES\n";
		else
		cout<<"NO\n";
		v.clear();
	}
	return 0;
}
