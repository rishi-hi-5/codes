#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;

int main(){
	int t;
	long size;
	long xor_res;
	cin>>t;

	while(t--){
		vector<long> v;
		vector<long> nv;
		cin>>size;
		size=2*size+2;
		long temp;
		for(long i=0;i<size;i++){
			cin>>temp;
			v.push_back(temp);
		}
		xor_res=v[0];
		for(long i=1;i<size;i++){
			xor_res^=v[i];
		}
		int bitpos=0;
		long res=xor_res;
		while((res&1)!=1){
			bitpos++;
			res=res>>1;
		}

		for(long i=0;i<size;i++){
			if(((v[i]>>bitpos)&1)==1){
				nv.push_back(v[i]);
			}
		}
		long xor_res_2;
		xor_res_2=nv[0];
		for(long i=1;i<nv.size();i++)
		{
			xor_res_2^=nv[i];
		}
		long a=xor_res_2;
		long b=xor_res^xor_res_2;

		a<b?(cout<<a<<" "<<b<<endl):(cout<<b<<" "<<a<<endl);
	}
	return 0;
}