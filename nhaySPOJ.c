#include<cstdio>
#include<cstring>
#define gc getchar_unlocked
#define ps push_back
using namespace std;
// int read_int()
// {
// 	char ch;
// 	ch=gc();
// 	if((char)ch=='\n')return 0;
// 	while(ch<'0'||ch>'9') ch=gc();
// 	int ret=0;
// 	while(ch>='0'&& ch<='9')
// 	{
// 		ret=ret*10+ch-48;
// 		ch=gc();
// 	}
// 	return ret;
// }

//vector<char> v1,s;
//vector<int> v2;
char v1[1000010];
char s[1000010];
int v2[1000010];

//prefix suffix logic that is used by kmp algorithm
void precompute(){
	int i,j;
	int v1size=strlen(v1);
	bool flag=false;
	v2[0]=0;
	for(int i=0,j=i+1;j<v1size;){
		if(v1[i]==v1[j]){
			v2[j]=i+1;
			i++;
			j++;
			flag=true;
		}
		else{
			if(flag==false){
					v2[j]=0;
					j++;
			}
			else
			{
				if(i==0){
					v2[j]=0;
					j++;
				}
				else
					i=v2[i-1];
			}
		}


	}
}

void kmp(){
	int ssize,v1size;
	ssize=strlen(s);
	v1size=strlen(v1);
	for(int i=0,j=0;i<ssize;){
		if(s[i]==v1[j]){ i++;j++; }
		else
		{ 
			j=v2[j-1];
			if(s[i]!=v1[j]){ i++;}
		}
		if(j>=v1size){printf("%d\n",(i-j));}
	}
}

int main(){
	
	int t;
	char ch;
	
	while(scanf("%d\n",&t)!=EOF){
		
		memset(v2,0,sizeof(v2));
		scanf("%s",v1);
		scanf("%s",s);
		if(strlen(v1)>strlen(s)){
			printf("\n");
			continue;
		}
		//v2.resize(v1.size());
		precompute();
		kmp();		
	}
	return 0;
}
