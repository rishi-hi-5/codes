#include<cstdio>
#include<iostream>

using namespace std;

char a[27][27];

const char*abc="ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main(){
	int key;
	key=0;
	for(int i=0;i<26;i++){
		for(int j=0;j<26;j++){
			if(i==0&&j==0) continue;
			a[i][j]=abc[key%26];
			key++;
		}
	}
	for(int i=0;i<26;i++){
		for(int j=0;j<26;j++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}

	return 0;

}