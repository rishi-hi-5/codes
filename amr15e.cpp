#include<cstdio>
#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#define gc getchar_unlocked
using namespace std;
long int read_int()
{
	char ch;
	ch=gc();
	while(ch<'0'||ch>'9') ch=gc();
	long int ret=0;
	while(ch>='0'&& ch<='9')
	{
		ret=ret*10+ch-48;
		ch=gc();
	}
	return ret;
} 
int main(){
	long int t;
	long int no,x;
	long int q;
	long int l,r;
	long int cnt,sum;
	vector<long int> v1,v2;
	t=read_int();
	while(t--){
		
		no=read_int();
		for(long int i=0;i<no;i++){
			cin>>x;
			v1.push_back(x);
		}
		q=read_int();
		for(long int i=0;i<q;i++){
			map<long int,long int> hash;
			l=read_int();
			r=read_int();
			cnt=0;
			sum=0;
			v2.clear();
			for(long int j=l-1;j<r;j++){
				if(hash[v1.at(j)]<1){
					hash[v1.at(j)]++;
					v2.push_back(v1.at(j));
				}
			}
			sort(v2.begin(),v2.end());
			for(long int i=0;i<v2.size();i++){
				sum+=(i+1)*v2.at(i);
			}
			cout<<sum<<endl;
		}	
	
	}
}
