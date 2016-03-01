#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;

int main(){
	int t;
	char*str;
	char ch;
	int size;
	int len;
	cin>>t;
	int k=t-1;
	while(t--){
		size=0;
		if(k==t)
			ch=getchar();
		//free(str);
		while((ch=getchar())!='\n'){
			size++;
			str=(char*)realloc(str,sizeof(char)*size);
			*(str+size-1)=ch;		
		}
		*(str+size)='\0';
		len=strlen(str);
		for(int i=0;i<len/2;i+=2){
			printf("%c",*(str+i));	
		}
		printf("\n");
	}
	free(str);
	return 0;
}
