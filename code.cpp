#include <iostream>
using namespace std;

int main() {
	int t,x;
	cin>>t;
	while(t!=0)
	{	
		cin>>x;
		if(x%2==0)
		cout<<x;
		else
		cout<<(x-1);
		cout<<"\n";
		t--;
	}

	return 0;
}
