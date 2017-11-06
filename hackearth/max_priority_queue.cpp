#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

void up_heapify(vector<long int> &v,long int n){
    if(n==1){
        return;
    }
    else if(v[n/2]<v[n]){
        v[n/2]=v[n/2]^v[n];
        v[n]=v[n/2]^v[n];
        v[n/2]=v[n/2]^v[n];
        up_heapify(v,n/2);
    }
}
void insert_in_heap(vector<long int> &v,long int e){
    v.push_back(e);
    v[0]++;
    up_heapify(v,v[0]);
}


int main()
{   
    long int n,e,q;
    int op;
    vector<long int> v;
    v.push_back(0);
    cin>>n;
    while(n--){
        cin>>e;
        insert_in_heap(v,e);
    }
    cin>>q;
    while(q--){
        cin>>op;
        if(op==1){
            cin>>e;
            insert_in_heap(v,e);
        }
        if(op==2)
            cout<<v[1]<<endl;
    }
    return 0;
}
