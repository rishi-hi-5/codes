#include<stdio.h>
#include<stdlib.h>
int main(){
	char* str;
	int len=0;
	int i;
	char ch;
	i=0;
	int j=0,k;
	int l;
	str=malloc(sizeof(char)*255);
	while((ch=getchar())!='\n'){
		*(str+i)=ch;
		i++;
	}
	//scanf("%25s",str);
	str[i]='\0';
	//printf("%s",str);
	for(i=0;str[i]!='\0';i++)len++;
	for(i=0;i<=len;i++){
		if(*(str+i)==' '||i==len){
			k=i;
			for(l=k-1;l>=j;l--){
				if(*(str+l)>=65&&*(str+l)<=91&&(*(str+l)==' '||l==k-1))
					printf("%c",str[l]);
				else if(str[l]>=97&&str[l]<=123&&(str[l]==' '||l==k-1))
					printf("%c",str[l]-32);
				else
					printf("%c",str[l]);
			}
			printf(" ");
			j=k;
			i=k;
		}
	}
	printf("\n");
	free(str);
return 0;
}
