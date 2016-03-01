#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int t,no1,i,j,k,temp,flag,no2,kk,cnt;
	vector<int> v1;
	vector<int> v2;
	scanf("%d",&kk);
	t=1;
	while(kk--)
	{
		flag=0;
		for(j=0;j<2;j++)
		{
			scanf("%d",&no1);
			no1=no1-1;
			for(i=0;i<16;i++)
			{
				if(i>=(no1*4)&&i<(no1*4)+4)
				{
					scanf("%d",&temp);
					v1.push_back(temp);
				}
				else
					scanf("%d",&temp);
			}
			if(flag==0)
			{
				flag=1;
				v2=v1;
				v1.clear();
				no2=no1;
			}
		}
		sort(v1.begin(),v1.end());
		sort(v2.begin(),v2.end());
		cnt=0;
		for(i=0;i<4;i++)
		{
			if(v1[i]==v2[i])
			{
				cnt++;			
			}
			
			if(no1==no2&&cnt==2)
			{
				cout<<"Case #"<<t<<": Bad magician!\n";
				break;
			}
		}
		if(cnt<2)
		{	
			flag=0;
			for(i=0;i<4;i++)
			{
				for(j=0;j<4;j++)
				{
					if(v1[i]==v2[j])
					{
						cout<<"Case #"<<t<<": "<<v1[i]<<"\n";
						flag=1;
						break;
					}
				}
				if(flag==1)
					break;
			}
		}
		if(flag==0)
			cout<<"Case #"<<t<<": Volunteer cheated!\n";
		t++;
	}
	return 0;
}
