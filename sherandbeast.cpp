#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int t,n;
    string str;
    int flag;
    cin>>t;
    while(t--){
        cin>>n;
        flag=0;
        for(int i=0;i<=n;i++){
            str=""; 
            if((n-i)%3==0&&i%5==0){
                flag=1;
               for(int j=0;j<(n-i);j++)
                   str+='5';
               for(int j=0;j<i;j++)
                   str+='3';
               break;
            }
        }
        if(flag==0){
            cout<<"-1"<<"\n";
            continue;
        }
        cout<<str<<"\n";
    }
    return 0;
}

