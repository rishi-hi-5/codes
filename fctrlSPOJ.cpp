#include<cstdio>

int main(){
	long long int t,n;
	long long int count;
	scanf("%lld",&t);
	while(t--){
		count=0;
		scanf("%lld",&n);
		for(long long int i=5;n/i>=1;i*=5){
			count+=n/i;
		}
		printf("%lld\n",count);
	}
	return 0;
}