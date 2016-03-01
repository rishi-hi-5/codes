#include<cstdio>
#include<iostream>
#include<cmath>
#define SECOND_VAL 360
using namespace std;

int give_me_no(int a){
	if(a==0)
		return 1;
	if(a==1){
		return 20;
	}
	else{
		return SECOND_VAL*(pow(20,a-2));
	}
}

int main(){
	int d_no;
	string str;
	int res=0;
	char ch;
	scanf("%d\n",&d_no);
	while(1){
		res=0;
		while(d_no){
			int count=0;
			while((ch=getchar())!='\n'){
				if(ch=='.'){
					count++;
				}
				else if(ch=='-'){
					count+=5;
				}
			}
			res+=give_me_no(d_no-1)*count;	
			d_no--;
		}
		cout<<res<<endl<<endl;
		scanf("%d",&d_no);
		if(d_no==0)
			break;	
		scanf("\n");
	}
	
	return 0;
}