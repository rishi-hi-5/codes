#include <cstdio>
#include <iostream>
using namespace std;

long int binary_search(long int a[],long int ss,long int se,long int temp){
    while(se>=ss){
        long int mid=(ss+se)/2;
        if(a[mid]==temp){
            return mid+1;
        }
        else if(a[mid]>temp){
            return binary_search(a,ss,mid-1,temp);
        }
        else if(a[mid]<temp){
            return binary_search(a,mid+1,se,temp);
        }
    }
    return -1;
}

int main(){
    long int size,temp,q,rank;
    cin>>size;
    long int a[size];
    for(long int i=0;i<size;i++){
        cin>>temp;
        a[i]=temp;
    }
    cin>>q;
    while(q--){
        cin>>temp;
        rank=binary_search(a,0,size-1,temp);
        cout<<rank<<endl;
    }
    return 0;
}