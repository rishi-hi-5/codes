#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;

int main(){
	vector<int> v;
	int no;
	int j,k,i;
	int ele;
	int temp;
	cout<<"enter the size of the array"<<endl;
	cin>>no;

	cout<<"enter the array"<<endl;

	for(int i=0;i<no;i++){
		cin>>ele;
		v.push_back(ele);
	}
	
	cout<<"sorted array using insertion sort is"<<endl;

	j=1;
	i=0;
	while(i<no-1){
		if(v[i]<=v[j]);
		else 
		{
			k=j;
			temp=v[j];
			k--;
			while(i<=k){
				v[k+1]=v[k];
				k--;
			}
			v[i]=temp;
		}
		j++;
		if(j==no){
			i++;
			j=i+1;
		}
	}
	for(int i=0;i<no;i++){
		cout<<v[i]<<" ";
	}
	cout<<endl;

	return 0;
}
