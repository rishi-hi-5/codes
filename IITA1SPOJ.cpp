#include<stdio.h>

//time complexity is log n  because there are at least log n bits in the
//for number n . so in the worst case if the below algorithm works it will work for
//at least n times for n bits

int cal_ham(int res){
	int count=0;
	while(res!=0){
		res=res&(res-1);
		count++;
	}
	return count;
}

int main(){
	long int a,b,res,t;
	scanf("%ld",&t);
	while(t--){
		scanf("%ld",&a);
		scanf("%ld",&b);
		printf("%d\n",cal_ham(a^b));
	}
}