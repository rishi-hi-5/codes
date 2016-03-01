#include<iostream>
using namespace std;

int main()
{	long long unsigned int no,t,fact[100],k=0;
	cin>>t;
	while(t!=0)
	{
		cin>>no;
		fact[k]=1;
		for(int i=1;i<=no;i++)
		fact[k]=fact[k]*i;
		t--;
		k++;
	}
	for(t=0;t<k;t++)
	{
		cout<<fact[t]<<"\n";
	}

	return 0;
}
