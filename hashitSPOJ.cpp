#include<cstdio>
#include<cstring>
//#include<cstdl>
struct ele{
	int key;
	char s[1000];
};
struct ele a[102];
const char*add_string="ADD:";
const char*delete_string="DEL:";

int get_ascii(char ch){
	return (int)ch;
}

int free_position(int hash_value){
	return (a[hash_value].key==0);	
}

int element_present(int i){
	return (a[i].key!=0);
}
int compare_str(char* s1,char*s2){
	if(!strcmp(s1,s2))
		return 1;
	else
		return 0;
}

int find_if_already_present(char* str){
	for(int i=0;i<102;i++){
		if(compare_str(a[i].s,str)){
			return 1;
		}
	}
	
		return 0;
}

int find_hash(char*str,int case_val){

	int hash_value,aarith=0;
	bool flag=true;

	if(case_val==1&&find_if_already_present(str))
		return -1;

	for(int i=0;i<strlen(str);i++){
		aarith+=(i+1)*get_ascii(str[i]);
	}
	
	hash_value=(19*aarith)%101;
	//while(hash_value>101)
	//		hash_value=hash_value%101;


	aarith=hash_value;

	if(compare_str(a[hash_value].s,str)&&case_val==1)
		return -1;

	if(case_val==2&&free_position(hash_value))
		return -1;

	//extra added case
	if(case_val==2&&!compare_str(a[hash_value].s,str))
		return -1;
	//now arrith denotes the previous has value
	//if the position at the given hash value is not free then follow the open addressing 
	//method given in the problem statement
	if((!free_position(hash_value))&&case_val!=2){
		for(int j=0;j<=19;j++){
			if(free_position((hash_value+j*j+23*j)%101)){
				hash_value=(hash_value+j*j+23*j)%101;
				flag=false;
				break;
			}
		}
		if(flag==true)//that is if the old hash value is equal to new has value then dont
			return -1;//the operation regarding insert or delete 
		else 
			return hash_value;
	}
	else
		return hash_value;
}

int main(){
	int t,cnt;
	int n;
	struct ele e;
	int case_val;
	char str[1000];
	scanf("%d",&t);
	int hash_value;
	while(t--){
		cnt=0;
		scanf("%d",&n);
		memset(a,0,sizeof(a));
		while(n--){
			scanf("%s",str);
			case_val=1;
			for(int i=0;i<4;i++){
				if(str[i]!=add_string[i]){
					case_val=2;
					break;
				}
			}
			hash_value=find_hash(str+4,case_val);
			//first check whether we the operation is add or delete
			
			if(hash_value==-1){//that is we did not found any hash
				continue;
			}
			switch(case_val){
				case 1:{
					e.key=hash_value;
					strcpy(e.s,str+4);
					cnt++;		
				}
				break;
				case 2:{
					e.key=0;
					strcpy(e.s,"\0");
					cnt--;
				}
				break;
				default:
					printf("what the fuck\n");
			}
			a[hash_value]=e;
		}
		//print the number of hash elements present in the has
		printf("%d\n",cnt);
		//now once we do all the operations print the string with respective hash values
		//101 are the number of elements in the hash table 
		for(int i=0;i<101;i++){
			if(element_present(i)){
				printf("%d:%s\n",a[i].key,a[i].s);
			}
		}	
	}
	return 0;
}