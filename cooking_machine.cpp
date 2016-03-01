#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;

void swap(long long int *a,long long int*b){
	int temp;

	if(*a>*b){
		temp=*a;
		*a=*b;
		*b=temp;
	}
}
int main(){
	long long int a,b,t;
	long long int cnt;
	cin>>t;
	while(t--){
		cnt=0;
		cin>>a;
		cin>>b;
		if(a==b){
			cout<<"0\n";
			continue;
		}
		swap(&a,&b);
		while(a%2!=0&&a!=1){
			a=(a-1)/2;
			cnt++;
		}
		cnt+=(log2(b*1.0)-log2(a*1.0));
		cout<<cnt<<endl;
	}
	return 0;
}
