#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<cstdlib>
#include<limits>
#include<algorithm>
#define MAX 2500
using namespace std;
int m,n;
int a[MAX][MAX];

int lcs(char* s1,char* s2){
	memset(a,0,sizeof(a));
	for(int i=0;i<=m;i++)
	{
		for(int j=0;j<=n;j++)
		{
			if(i==0)
				a[i][j]=j;
			else if(j==0)
				a[i][j]=i;
			else if(s1[i-1]==s2[j-1])
				a[i][j]=a[i-1][j-1];
			else
				a[i][j]=1+min(a[i-1][j],min(a[i][j-1],a[i-1][j-1]));
		//	cout<<a[i][j]<<" ";
		}
		//cout<<"\n";	
	}
	return a[m][n];
}

int main(){
	int t;
	int res;
	char str1[2500],str2[2500];
	scanf("%d",&t);	
	while(t--){
		scanf("%s",str1);
		scanf("%s",str2);
		
		m=strlen(str1);
		n=strlen(str2);
		res=lcs(str1,str2);
		cout<<res<<endl;
//		cout<<max(m,n)-res<<endl;
	}
	return 0;
}

