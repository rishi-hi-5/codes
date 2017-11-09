#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <climits>
using namespace std;
long int min(int a,int b){
	return a<b?a:b;
}

int print_seg_tree(long int seg[],long int size){
	for(long int i=0;i<size;i++){
		cout<<seg[i]<<" ";
	}
	cout<<endl;
}
long int construct_seg(long int seg[],long int a[],long int ss,long int se,long int pos){
	if(ss==se){
		seg[pos]=a[ss];
		return seg[pos];
	}

	long int mid=(ss+se)/2;
	seg[pos]=min(construct_seg(seg,a,ss,mid,2*pos),construct_seg(seg,a,mid+1,se,2*pos+1));
	return seg[pos];
}

long int range_min_query(long int seg[],long int ss,long int se,long int r1,long int r2,long int pos){
	if(ss>=r1 && r2>=se){
		return seg[pos];
	}
	if(ss==se){
		return INT_MAX;
	}
	long int mid=(ss+se)/2;
	return min(range_min_query(seg,ss,mid,r1,r2,2*pos),range_min_query(seg,mid+1,se,r1,r2,2*pos+1));
}

long int update_seg(long int seg[],long int ss, long int se,long int rpos,long int num,long int pos){
	if(ss>=rpos && se>=rpos){
		return seg[pos];
	}

	if(ss==se){
		if(ss==rpos)
			seg[pos]=num;
		return seg[pos];
	}

	long int mid=(ss+se)/2;
	seg[pos]=min(update_seg(seg,ss,mid,rpos,num,2*pos),update_seg(seg,mid+1,se,rpos,num,2*pos+1));
	return seg[pos];
}

int main(){
	long int n,q,temp,r1,r2,h,ss,se;
	cin>>n>>q;
	ss=0;se=n-1;
	char ch;
	h=ceil(log2(n));
	long int size=2*pow(2,h);
	long int seg[size];
	memset(seg,0,sizeof(seg));
	long int a[n];
	for(int i=0;i<n;i++){
		cin>>temp;
		a[i]=temp;
	}
	construct_seg(seg,a,ss,se,1);
	print_seg_tree(seg,size);
	while(q--){
		cin>>ch>>r1>>r2;
		if(ch=='q'){
			cout<<range_min_query(seg,ss,se,r1-1,r2-1,1)<<endl;
		}
		else if(ch=='u'){
			update_seg(seg,ss,se,r1-1,r2,1);
			print_seg_tree(seg,size);
		}
	}

	return 0;
}