#include<cstdio>
#include<iostream>
#include<string>
#include<cmath>
#include<cstring>
using namespace std;
int len;
int a[6110][6110];
string str1,str2,temp;
int lcs(){

	memset(a,0,sizeof(a));
	for(int i=0;i<=len;i++){
		for(int j=0;j<=len;j++){
			if(i==0||j==0)
				a[i][j]=0;
			else if(str1[i-1]==str2[j-1])
				a[i][j]=a[i-1][j-1]+1;
			else
				a[i][j]=max(a[i-1][j],a[i][j-1]);
		}
	}

	return a[len][len];
}
int main(){
	int t;
	int i,j;
	int res;
	cin>>t;
	while(t--){
		i=0;
		str1=str2="";
		cin>>str1;
		len=str1.length();
		for(i=len-1,j=0;i>=0;i--,j++){
			str2+=str1[i];
		}
		res=lcs();
		cout<<len-res<<endl;
	}
	return 0;
}
