#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
int a[3001];

using namespace std;
vector<int> v;
void sieve(){
	for(int i=2;i<3001;i++){
		if(a[i]==0){
			for(int j=2;j<3001;j++){
				if(i*j>3001)
					break;
				if(a[i*j]==-1)
					continue;

				a[i*j]++;
				if(a[i*j]>=3){
					a[i*j]=-1;
					v.push_back(i*j);
				}
			}
		}
	}
}

int main(){
	int t;
	int no;
	cin>>t;
	sieve();
	sort(v.begin(),v.end());
	//for(int i=0;i<v.size();i++)
	//	cout<<v[i]<<endl;
	while(t--){
		cin>>no;
		if(no>1000)
			cout<<"0"<<endl;
		else
		cout<<v[no-1]<<endl;
	}
	return 0;
}
