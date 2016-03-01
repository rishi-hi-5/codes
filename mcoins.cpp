#include<cstdio>
#include<iostream>
#include<vector>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
bool a[1000100];

int main(){
	vector<int> v,v2;
	int l,k,m,temp;
	memset(a,false,sizeof(a));
	cin>>l>>k>>m;
	for(int i=0;i<m;i++){
		cin>>temp;
		v.push_back(temp);
	}
	v2=v;
	sort(v.begin(),v.end());
	a[1]=a[k]=a[l]=true;
	for(int i=2;i<=v[m-1];i++){
		if(i==k||i==l)
			continue;
		if(i<k && i<l)
			a[i]=!a[i-1];
		else if(a[i-1]&&a[i-l]&&a[i-k])
			a[i]=false;
		else
			a[i]=true;
	}
	for(int i=0;i<v2.size();i++){
		if(a[v2.at(i)])
			cout<<"A";
		else
			cout<<"B";
	}
	cout<<endl;
	return 0;
}
