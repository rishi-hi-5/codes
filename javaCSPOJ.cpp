#include<cstdio>
#include<cctype>

char str[101];
int status_rec;

int scan(){
	//char ch;
	char inp[101];
	int ccount=0,jcount=0;
	status_rec=0;
	int i=-1;
	if(scanf("%s",inp)!=EOF){
		for(int j=0;inp[j]!='\0';j++){
			if(inp[j]==' ')
				continue;
			i++;
			str[i]=inp[j];
			if(i==0&&(str[i]=='_'||(str[i]>='A'&&str[i]<='Z'))){
				status_rec=3;
			}
			if(str[i]=='_'&&status_rec!=3){ 
				if(str[i-1]=='_'){
					status_rec=3;
					ccount=0;
					continue;
				}
				ccount++;
			}
			else if(str[i]>='A'&&str[i]<='Z'&&status_rec!=3) jcount++;
		}
	}
	str[i+1]='\0';
	if(str[i]=='_')
		status_rec=3;
	else if(ccount>0&&jcount>0){
		status_rec=3;
	}
	else if(ccount>0&&jcount==0){
		status_rec=2;
	}
	else if(ccount==0&&jcount>0){
		status_rec=1;
	}
	return i;
}

int main(){	
	int size;

	while(1){
		if((size=scan())==-1)break;
		switch(status_rec){
			case 2:
				status_rec=0;
				for(int i=0;str[i]!='\0';i++){
					if(str[i]=='_'){
						status_rec=1;
						continue;
					}
					if(status_rec==1){
						status_rec=0;
						printf("%c",toupper(str[i]));
					}
					else
						printf("%c",str[i]);
				}
			break;
			case 1:
				status_rec=0;
				for(int i=0;str[i]!='\0';i++){
					if(str[i]>='A'&&str[i]<='Z'){
						printf("_%c",tolower(str[i]));
					}
					else
						printf("%c",str[i]);
				}
			break;
			case 3:
				printf("Error!");
			break;
			default:
				for(int i=0;i<str[i]!='\0';i++)
					printf("%c",str[i]);
		}
		printf("\n");
	}
	return 0;
}