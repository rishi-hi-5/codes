#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
using namespace std;

int main(){
	int t;
	string str;
	cin>>t;
	while(t--){
		cin>>str;
		for(int i=0;i<str.length()/2;i+=2)
			cout<<str[i];
		cout<<endl;
	}
	return 0;
}
