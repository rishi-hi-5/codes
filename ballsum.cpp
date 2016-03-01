#include<cstdio>
#include<iostream>
#define gc getchar_unlocked
using namespace std;
long long int read_int()
{
	char ch;
	ch=gc();
	while(ch<'0'||ch>'9') ch=gc();
	long long int ret=0;
	while(ch>='0'&& ch<='9')
	{
		ret=ret*10+ch-48;
		ch=gc();
	}
	return ret;
} 
/*

long long int gcd(long int a,long int b){

	while(a!=b){
		if(a<b)
			b=b-a;
		else
			a=a-b;
	}
	return a;
}
*/



long long int gcd(long long int a, long long int b)
{

    if(b == 0) {
            return a;
    }
    else {
    	if(a>b)
        	return gcd(b, a % b);
        else
        	return gcd(a, b % a);
    }
}


int main(){

	long long int n,k,num,deno,g;
	scanf("%lld%lld",&n,&k);
	while(n!=-1&&k!=-1){
		deno=n*n-n;
		num=0;
		for(long long int i=1;i<k;i++){
			if(i%2==0)
				num+=i;
			else
				num+=(i-1);
		}
		if(num==0)
			printf("0\n");
		else if((num*1.0/deno)==1.0)
			printf("1\n");
		else{
			g=gcd(num,deno);
			printf("%lld/%lld\n",(num/g),(deno/g));
		}
		scanf("%lld%lld",&n,&k);
	}
	return 0;
}
