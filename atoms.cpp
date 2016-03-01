#include<cstdio>
#include<iostream>
using namespace std;

int main(){

	long long int p,n,m,k,i;
	double sum;

	scanf("%lld",&p);
	while(p--){
		scanf("%d%d%d",&n,&m,&k);
		if(n==m&&m==k&&(k==1||k==0)){
			printf("0\n");
			continue;
		}
		if(m==0&&n==k)
		{
			printf("0\n");
			continue;
		}
		sum=n*m;
		for(i=0;sum<=k;i++){
			sum*=m;
		}
		printf("%lld\n",i);
	}

	return 0;
}
