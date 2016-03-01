#include<iostream>
using namespace std;
int main()
{
	int r,p1,p2,m,l,ps1=0,ps2=0,max1=0,max2=0;
	cin>>r;
	while(r!=0)
	{
		cin>>p1>>p2;
		ps1+=p1;
		ps2+=p2;
		if(ps1>ps2)
		{
			l=p1-p2;
			if(l>max1)
			{
				max1=l;
			}
		}
		else
		{
			l=p2-p1;
		
			if(l>max2)
			{
				max2=l;
			}
		}


		r--;
	}
	cout<<"\n";
	if(max1>max2)
	cout<<1<<" "<<max1;
	else
	cout<<2<<" "<<max2;
	return 0;
}
