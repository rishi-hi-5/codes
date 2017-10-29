#include<cstdio>
#include<iostream>

using namespace std;

void swap(int&a,int &b){
	a=a^b;
	b=a^b;
	a=a^b;
}



int gcd_eq(int a,int b){
	if(a<b)
		swap(a,b);
	ggg(int a,int b);
}


int main(){
	int a,b;
	
	cout<<"Enter the number a and b "<<endl;
	cin>>a>>b;
	cout<<gcd_eq(a,b);	
	return 0;
}
