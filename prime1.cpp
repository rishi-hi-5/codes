#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
int a[32000];

void sieve(){
	for(int i=2;i<50;i++){
		if(a[i]==0)
			for(int j=2;j<16000;j++){
				if(i*j>32000)
					break;
				else
					a[i*j]=1;
			}
	}
}
int main(){
	int t;
	int m,n;
	sieve();
	cin>>t;
	while(t--){
		cin>>m>>n;
		/*if(n<32000){
			for(int i=m;i<=n;i++){
				if(a[i]==0&&i>1)
				cout<<i<<endl;
			}
		}*/
	//	else
		{
			vector<int> v;
			int* res=new int[n-m];
			for(int i=2;i<=32000;i++){
				if(a[i]==0){
					for(int j=m+m%i;j<=n;j+=i){
						if(res[j-m]==0)
							res[j-m]++;
					}
				}
			}
			for(int i=0;i<=n-m;i++)
				if(res[i]==0)
					cout<<i+m<<endl;
		}
	}
	return 0;
}
