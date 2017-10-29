#include<cstdio>
#include<iostream>

using namespace std;

void swap(int *a,int *b){
	int temp=*a;
	*a=*b;
	*b=temp;
}

int partition(int a[],int l ,int r){
	int pivot=a[r];
	int i=l-1;
	for(int j=l;j<r-1;j++){
		if(a[j]<p=ivot){
			i++;
			swap(&a[i],&a[j]);
		}
	}
	swap(&a[i+1],&a[r]);
	return i+1;
}

void quicksort(int a[],int l,int r){
	if(l<r){
		int p=partition(a,l,r);
		quicksort(a,l,p-1);
		quicksort(a,p+1,r);
	}
}

int main(){
	int a[5];
	int t;
	cout<<"enter the 5 elements array"<<endl;
	for(int i=0;i<5;i++)
		cin>>a[i];

	quicksort(a,0,4);
	cout<<endl;
	for(int i=0;i<5;i++){
		cout<<a[i]<<" ";
	}
	return 0;
}