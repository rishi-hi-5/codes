
//correct this fucker something is going wrong

#include<cstdio>
#include<iostream>

using namespace std;

int a[5];


void merge(int a[],int s,int mid,int e){
	int left[mid-s+1];
	int right[e-mid];

	//make the left sub array
	for(int i=0;i<(mid-s+1);i++)
		left[i]=a[s+i];

	//make the right sub array

	for(int i=0;i<(e-mid);i++)
		right[i]=a[mid+i];

	int i,j,k;
	//merge the arrays
	for(i=0,j=0,k=0;j<mid-s+1||k<e-mid;){
		if(left[j]>right[k]){
			a[i]=right[k];
			k++;
		}
		else if (left[j]<right[k]){
			a[i]=left[j];
			j++;
		}
		else{
			a[i]=left[j];
			j++;
			k++;
		}
		i++;
	}
	if(j<mid-s+1){
		while(j<mid-s+1){
		a[i]=left[j];
		j++;
		i++;
		}
	}
	else if(k<e-mid){
		while(k<e-mid){
		a[i]=right[k];
		k++;
		i++;
		}	
	}

}

void mergesort(int a[],int s,int e){
	if(s<e){
		int mid =s+(e-s)/2;
		mergesort(a,s,mid);
		mergesort(a,mid+1,e);
		merge(a,s,mid,e);
	}
}

int main(){

	int t;
	cout<<"enter the 5 elements array"<<endl;
	for(int i=0;i<5;i++)
		cin>>a[i];

	mergesort(a,0,5);
	cout<<endl;
	for(int i=0;i<5;i++){
		cout<<a[i]<<" ";
	}
	return 0;
}