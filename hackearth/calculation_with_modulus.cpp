#include<cstdio>
#include<iostream>

using namespace std;

long int mod_expo(long int a,long int b,long int m){
	long int res=a;
	for(long int i=0;i<b-1;i++){
		res=(res%m)*(a%m);
	}
	return res;
}

long int d,x,y;

void extended_euclidean(long int a,long int b){
	if(b==0){
		d=a;
		x=1;
		y=0;
	}
	else{
		extended_euclidean(b,a%b);
		long int temp=x;
		x=y;
		y=temp-(a/b)*y;
	}
}

long int mod_inv(long int c,long int m){
	extended_euclidean(c,m);
	return ((x%m)+m)%m;
}


int main(){
	long int a,b,c,m,res1,res2;
	scanf("%ld %ld %ld %ld",&a,&b,&c,&m);
	res1=mod_expo(a,b,m);
	res2=mod_inv(c,m);
	cout<<((res1%m)*(res2%m)%m)<<endl;
	return 0;
}