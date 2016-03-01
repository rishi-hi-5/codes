#include<cstdio>
#include<iostream>
#include<vector>
#define gc getchar_unlocked
#define ps push_back
using namespace std;
int read_int()
{
	char ch;
	ch=gc();
	if((char)ch=='\n')return 0;
	while(ch<'0'||ch>'9') ch=gc();
	int ret=0;
	while(ch>='0'&& ch<='9')
	{
		ret=ret*10+ch-48;
		ch=gc();
	}
	return ret;
}

vector<char> v1,s;
vector<int> v2;

//prefix suffix logic that is used by kmp algorithm
void precompute(){
	int i,j;
	bool flag=false;
	v2[0]=0;
	for(int i=0,j=i+1;j<v1.size();){
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
	for(int i=0,j=0;i<s.size();){
		if(s[i]==v1[j]){ i++;j++; }
		else
		{ 
			j=v2[j-1];
			if(s[i]!=v1[j]){ i++;}
		}
		if(j>=v1.size()){cout<<(i-j)<<endl;}
	}
}

int main(){
	
	int t;
	char ch;
	
	while(scanf("%d\n",&t)!=EOF){
		v1.clear();
		v2.clear();
		s.clear();
		while((ch=gc())!='\n'){
			v1.ps(ch);	
		}
		while((ch=gc())!='\n'){
			s.ps(ch);	
		}
		if(v1.size()>s.size()){
			cout<<endl;
			continue;
		}
		v2.resize(v1.size());

		precompute();
		kmp();		
	}
	return 0;
}
