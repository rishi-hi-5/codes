#include<cstdio>
#include<cstring>
char s1[1000];
char s2[1000];
char res[2002];
int carry;
int give_me_integer(char ch){
	return (int)ch-48;
}

int perform_multi(int a,int b){
	int res=a*b;
	return res;
}

char handle(char ch){
	if(ch=='\0') return (char)(48);
	else return ch;

}
int check_carry(int res){
	int val;
	if(res>9){
		val=res%10;
		res=res-val;
		carry=res/10;
		res=val;
	}
	else
		carry=0;
	return res;
}
int main(){
	int t;
	int len1,len2;
	scanf("%d",&t);
	while(t--){
		carry=0;
		scanf("%s",s1);
		scanf("%s",s2);
		len1=strlen(s1);
		len2=strlen(s2);
		for(int i=0;i<len1;i++){
			for(int j=0;j<len2;j++){//len2+len1+
				res[(len1-1-i)+(len2-1-j)]=(char)(check_carry((give_me_integer(handle(res[(len1-1-i)+(len2-1-j)]))+perform_multi(give_me_integer(s1[len1-1-i]),give_me_integer(s2[len2-1-j]))+carry))+48);
			}
		}

		if(carry!=0){
			printf("%d",carry);
			printf("%s\n",res);
		}
		else
			printf("%s\n",res);
	}
	return 0;
}