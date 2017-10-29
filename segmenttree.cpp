#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;

int size=15;
int seg[16]={0};

void constructSeg(int ss,int se,int a[],int pos){
	if(ss==se){
		seg[pos]=a[ss];
		return;
	}
	if(ss>se)
		return;
	int mid=ss+(se-ss)/2;
	constructSeg(ss,mid,a,2*pos);
	constructSeg(mid+1,se,a,2*pos+1);
	seg[pos]=seg[2*pos]+seg[2*pos+1];
}
int sum=0;
void print_sum(int ss,int se,int fins,int fine,int pos){
	if(ss>=fins && se<=fine){
		sum+= seg[pos];
		return;
	}
	if(ss==se)
		return;
	int mid=ss+(se-ss)/2;
	print_sum(ss,mid,fins,fine,2*pos);
	print_sum(mid+1,se,fins,fine,2*pos+1);
}

void update_arr(int ss,int se,int ele_pos,int update_num,int seg_pos){
	if(ss<=ele_pos && se>=ele_pos){
		seg[seg_pos]+=update_num;
	}
	if(ss==se)
		return;
	int mid=ss+(se-ss)/2;
	update_arr(ss,mid,ele_pos,update_num,seg_pos*2);
	update_arr(mid+1,se,ele_pos,update_num,seg_pos*2+1);
}

int main(){
	int a[6]={1,3,5,7,9,11};
	int update_num=4;
	int ss=0,se=5;
	constructSeg(ss,se,a,1);
	for(int i=0;i<=size;i++){
		cout<<seg[i]<<" ";
	}
	print_sum(0,5,3,5,1);
	cout<<"sum is "<<sum<<endl;
	// we will update the 4th array element
	update_arr(0,5,3,update_num-a[3],1);
	for(int i=0;i<=size;i++){
		cout<<seg[i]<<" ";
	}
	cout<<endl;
	sum=0;
	print_sum(0,5,3,5,1);
	cout<<"sum is "<<sum<<endl;
	return 0;
}