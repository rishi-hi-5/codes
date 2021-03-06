#include <stdio.h>
#include <assert.h>
 
int xyz[100000];
 
void reorganizeArray(int N){
	int i;
	for (i=0;i<N;i++){
		if (i<N/2)
			xyz[i] = i*2+1;
		else
			xyz[i] = 2*(i-N/2);
	}
}
 
int main(){
	int T,N;
	int i;
	int count, total, temp;
	long long int result; 
 
	scanf("%d", &T);
	
	while (T>0){
		T--;
		scanf("%d", &N);
		count = 0;
		total = 0;
		result = 1;
		reorganizeArray(N);
		while(total<N){
			i = total;
			while (xyz[i]!=count){
				temp = xyz[i];
				xyz[i] = count;
				i = temp;
			}
			while (total<N && xyz[total]<=count)
				total++;
			count++;
		}
		while (count>0){
			count--;
			result = (result * 26) % 1000000007;
		} 
		printf("%lld\n", result);
	}	
	return 0;
}