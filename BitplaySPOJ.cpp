/*
Problem :
The problem is very simple.

You are given a even number N and an integer K and you have to find the greatest odd number M less than N such that the sum of digits in binary representation of M is atmost K.
Input
For each testcase
You are given an even number **N** and an integer **K**

For each testcase

You are given an even number N and an integer K

 
Output

For each test case, output the integer M  if it exists, else print -1


*/
#include<cstdio>
#include<iostream>

using namespace std;

int main(){

	//number of the testcases
	int t;
	//given even number
	long int n;
	//number of ones the binary representation can have
	long int k;
	//result is stored in the following variable
	long int res,x;
	scanf("%d",&t);
	while(t--){
		scanf("%ld%ld",&n,&k);
		x=1;
		res=0;
		x=x<<32;

		if(n==1){
			cout<<"1"<<endl;
			continue;
		}
		//There is no such odd number which doesnt contain 1 in it
		if(k==0){
			cout<<"-1"<<endl;
			continue;
;		}
		//k--;
		for(int i=32;i>=0&&k!=0;i--){
			res|=x;
			if(res>=n){
				res^=x;
			}
			else{
				k--;
			}
			x=x>>1;
		}
		cout<<res<<endl;
	}

	return 0;
}